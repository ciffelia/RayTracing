#pragma once

#include <Siv3D.hpp>
#include "Scene.hpp"
#include "Utils.hpp"
#include "Constants.hpp"
#include "Material.hpp"

struct SceneRenderer {
	Scene scene;

	explicit SceneRenderer(const Scene _scene)
		: scene(_scene)
	{ }

	// 光線を飛ばして投影面の色を返す
	ColorF color(const Ray ray, const int depth = 0) const
	{
		if (depth > Constants::MaxRecurse)
			return Palette::Black;

		auto hitRec = scene.trace(ray);
		if (hitRec)
		{
			const auto scatterRec = hitRec->materialPtr->scatter(ray, hitRec.value());
			if (scatterRec)
			{
				return color(scatterRec->ray, depth + 1) * scatterRec->albedo;
			}
			
			return Palette::Black;
		}

		const double lerpT = ray.direction.y + 1.0 * 0.5;
		return ColorF(1.0, 1.0, 1.0).lerp(ColorF(0.5, 0.7, 1.0), lerpT);
	}
	
	// 複数の光線を飛ばしてサンプリングした投影面の色を返す
	ColorF sampleColor(const Vec2 imagePlanePos, const int samples) const
	{
		ColorF result(0.0, 0.0, 0.0);

		for (const auto i : step(samples))
		{
			const auto sampleRandomMax = scene.imagePlane.size / scene.camera.resolution;
			const auto sampleImagePlanePos = imagePlanePos + RandomVec2(sampleRandomMax.x, sampleRandomMax.y);

			const auto sampleColor = color(scene.rayAt(sampleImagePlanePos));
			result += sampleColor;
		}

		result *= 1.0 / samples;

		return result;
	}

	// レンダリング
	Image render(const int samples) const
	{
		Image image(scene.camera.resolution);

#pragma omp parallel for schedule(dynamic)
		for (int y = 0; y < scene.camera.resolution.y; ++y)
		{
			const double imagePlaneX = scene.imagePlane.size.y * (static_cast<double>(y) / scene.camera.resolution.y);

			for (int x = 0; x < scene.camera.resolution.x; ++x)
			{
				const double imagePlaneY = scene.imagePlane.size.x * (static_cast<double>(x) / scene.camera.resolution.x);

				// 投影面上の座標
				const Vec2 imagePlanePos(imagePlaneY, imagePlaneX);

				// 色を計算する
				// サンプル数1の場合はサンプリングしない
				const auto pointColor =
					samples == 1
					? color(scene.rayAt(imagePlanePos))
					: sampleColor(imagePlanePos, samples);

				Point(x, y).overwrite(image, Utils::LinearToGamma(pointColor, Constants::GammaValue));
			}
		}

		return image;
	}
};
