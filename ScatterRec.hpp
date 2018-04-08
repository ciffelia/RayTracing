#pragma once

#include <Siv3D.hpp>

#include "Ray.hpp"

namespace RayT {
	// U—‚Ìî•ñ
	struct ScatterRec
	{
		// U—Œã‚ÌV‚µ‚¢Œõü
		Ray ray;

		// ”½Ë—¦
		ColorF albedo;

		constexpr ScatterRec(const Ray _ray, const ColorF _albedo)
			: ray(_ray)
			, albedo(_albedo)
		{ }
	};
}
