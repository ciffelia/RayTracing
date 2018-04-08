#pragma once

#include <Siv3D.hpp>

namespace RayT {
	// ƒJƒƒ‰
	struct Camera {
		// À•W
		Vec3 pos;

		// ‰ğ‘œ“x
		Size resolution;

		Camera() = default;

		constexpr Camera(const Vec3 _pos, const Size _resolution)
			: pos(_pos)
			, resolution(_resolution)
		{ }
	};
}
