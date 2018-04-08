#pragma once

#include <Siv3D.hpp>

namespace RayT {
	// ���e��
	struct ImagePlane {
		// ���S���W
		Vec3 center;

		// �傫��
		Vec2 size;

		ImagePlane() = default;

		constexpr ImagePlane(const Vec3 _center, const Size _size)
			: center(_center)
			, size(_size)
		{ }
	};
}
