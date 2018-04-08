#pragma once

#include <Siv3D.hpp>

namespace RayT {
	// “Š‰e–Ê
	struct ImagePlane {
		// ’†SÀ•W
		Vec3 center;

		// ‘å‚«‚³
		Vec2 size;

		ImagePlane() = default;

		constexpr ImagePlane(const Vec3 _center, const Size _size)
			: center(_center)
			, size(_size)
		{ }
	};
}
