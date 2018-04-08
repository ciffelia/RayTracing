#include <Siv3D.hpp> // OpenSiv3D v0.2.4

#include "Scene.hpp"
#include "ImagePlane.hpp"
#include "SceneRenderer.hpp"
#include "Constants.hpp"
#include "Lambertian.hpp"
#include "Metal.hpp"

// Sceneのパラメータ設定
Scene buildScene()
{
	constexpr Camera camera({ 0, 0, 0 }, { 400, 200 });
	constexpr ImagePlane imagePlane({ 0, 0, -1 }, { 4, 2 });

	Scene scene(camera, imagePlane);

	scene.spheres.emplace_back(Vec3(0.6, 0, -1), .5, std::make_shared<Lambertian>(ColorF(.1, .2, .5)));
	scene.spheres.emplace_back(Vec3(-0.6, 0, -1), .5, std::make_shared<Metal>(ColorF(.8, .8, .8), 1));
	scene.spheres.emplace_back(Vec3(0, -100.5, -1), 100, std::make_shared<Lambertian>(ColorF(.8, .8, 0)));

	return scene;
}

void Main()
{
	Window::Resize(400, 200);

	const Scene scene = buildScene();
	
	// 処理時間の計測
	const MillisecClock clock;

	const Image image = SceneRenderer(scene).render(Constants::Samples);

	// 計測結果を出力
	clock.print();

	const Texture texture(image);

	while (System::Update())
	{
		texture.draw();
	}
}
