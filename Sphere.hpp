#pragma once

#include <Siv3D.hpp>

// ‹…
struct Sphere
{
	Vec3 center;
	double r;

	Sphere() = default;

	constexpr Sphere(const Vec3 _center, const double _r)
		: center(_center)
		, r(_r)
	{ }
};
