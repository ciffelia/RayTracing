#pragma once

#include <Siv3D.hpp>

#include "Sphere.hpp"
#include "Camera.hpp"
#include "Ray.hpp"
#include "HitRec.hpp"
#include "ImagePlane.hpp"

namespace RayT {
	struct Scene
	{
		// 球のリスト
		Array<Sphere> spheres;

		// カメラ
		Camera camera;

		// 投影面
		ImagePlane imagePlane;

		Scene(const Camera _camera, const ImagePlane _imagePlane)
			: camera(_camera)
			, imagePlane(_imagePlane)
		{ }

		// スクリーン上の座標に向かう光線を返す
		constexpr Ray rayAt(const Vec2 pos) const
		{
			// スクリーン上の3次元座標
			const Vec3 pos3D(
				imagePlane.center.x - imagePlane.size.x / 2 + pos.x,
				-(imagePlane.center.y - imagePlane.size.y / 2 + pos.y),
				imagePlane.center.z
			);

			return Ray(camera.pos, (pos3D - camera.pos).normalized());
		}

		// 光線と球の衝突判定
		// 衝突する場合は光線の始点からの距離を、衝突しない場合はnoneを返す
		Optional<double> intersects(const Ray ray, const Sphere sphere) const
		{
			const auto co = ray.origin - sphere.center;

			const double a = ray.direction.dot(ray.direction);
			const double b = 2 * ray.direction.dot(co);
			const double c = co.dot(co) - sphere.r * sphere.r;

			const double d = b * b - 4 * a * c;

			// 判別式が0以下だった場合
			// 方程式の解は0個か1個であるから、光線と球は交点を持たない
			if (d <= 0)
				return none;

			// 小さい方の解が正だった場合
			// 始点から近い交点が始点の表側にある
			if (-b - Math::Sqrt(d) > 0.001)
				return (-b - Math::Sqrt(d)) / (2 * a);

			// 小さい方の解が負で、大きい方の解が正だった場合
			// 始点から近い交点は始点の裏側にあるが、
			// 始点から遠い交点が始点の表側にある
			if (-b + Math::Sqrt(d) > 0.001)
				return (-b + Math::Sqrt(d)) / (2 * a);

			// 解が2つとも負だった場合
			// 2つの交点はどちらも始点の裏側にある
			return none;
		}

		// 光線を飛ばす
		// 物体に衝突した場合はその情報を、しなかった場合はnoneを返す
		Optional<HitRec> trace(const Ray ray) const
		{
			Optional<HitRec> closestHit;

			for (const auto& sphere : spheres)
			{
				const auto t = intersects(ray, sphere);

				if (!t)
					continue;
				if (closestHit && closestHit->t < t)
					continue;

				const auto p = ray.origin + ray.direction * t.value();
				closestHit = HitRec(t.value(), p, (p - sphere.center).normalized(), sphere.materialPtr);
			}

			return closestHit;
		}
	};
}
