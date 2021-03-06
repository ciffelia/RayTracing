#pragma once

#include <Siv3D.hpp>

namespace RayT {
	// 光線
	struct Ray
	{
		// 始点
		Vec3 origin;

		// 方向
		Vec3 direction;

		Ray() = default;

		constexpr Ray(const Vec3 _start, const Vec3 _direction)
			: origin(_start)
			, direction(_direction)
		{ }
	};
}
