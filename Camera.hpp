#pragma once

#include <Siv3D.hpp>

namespace RayT {
	// カメラ
	struct Camera {
		// 座標
		Vec3 pos;

		// 解像度
		Size resolution;

		Camera() = default;

		constexpr Camera(const Vec3 _pos, const Size _resolution)
			: pos(_pos)
			, resolution(_resolution)
		{ }
	};
}
