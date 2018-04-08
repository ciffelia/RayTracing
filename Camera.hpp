#pragma once

#include <Siv3D.hpp>

namespace RayT {
	// �J����
	struct Camera {
		// ���W
		Vec3 pos;

		// �𑜓x
		Size resolution;

		Camera() = default;

		constexpr Camera(const Vec3 _pos, const Size _resolution)
			: pos(_pos)
			, resolution(_resolution)
		{ }
	};
}
