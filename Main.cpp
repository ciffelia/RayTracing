#include <Siv3D.hpp> // OpenSiv3D v0.2.4

#include "Scene.hpp"
#include "ImagePlane.hpp"
#include "SceneRenderer.hpp"
#include "Constants.hpp"
#include "Lambertian.hpp"
#include "Metal.hpp"

// Sceneのパラメータ設定
RayT::Scene buildScene()
{
	constexpr RayT::Camera camera({ 0, 0, 2 }, { 400, 200 });
	constexpr RayT::ImagePlane imagePlane({ 0, 0, 0 }, { 4, 2 });

	RayT::Scene scene(camera, imagePlane);

	// 左の赤い球
	scene.spheres.emplace_back(
		Vec3(-1.2, 0, 0), .5,
		std::make_shared<RayT::Lambertian>(ColorF(.7, .3, .9))
	);

	// 中央の黄色い球
	scene.spheres.emplace_back(
		Vec3(0, 0, 0), .5,
		std::make_shared<RayT::Metal>(ColorF(.9, .7, .3), 0)
	);

	// 右の緑色の球
	scene.spheres.emplace_back(
		Vec3(1.2, 0, 0), .5,
		std::make_shared<RayT::Metal>(ColorF(.3, .9, .7), .3)
	);

	// 下の大きな球
	scene.spheres.emplace_back(
		Vec3(0, -100.5, 0), 100,
		std::make_shared<RayT::Lambertian>(ColorF(.8, .8, 0))
	);

	return scene;
}

void Main()
{
	Window::Resize(400, 200);

	const RayT::Scene scene = buildScene();
	
	// 処理時間の計測
	const MillisecClock clock;

	const Image image = RayT::SceneRenderer(scene).render(RayT::Constants::Samples);

	// 計測結果を出力
	clock.print();

	const Texture texture(image);

	while (System::Update())
	{
		texture.draw();
	}
}
