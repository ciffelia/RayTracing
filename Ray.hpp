#pragma once

#include <Siv3D.hpp>

// Œõü
struct Ray
{
	Vec3 origin;
	Vec3 direction;

	Ray() = default;

	constexpr Ray(const Vec3 _start, const Vec3 _direction)
		: origin(_start)
		, direction(_direction)
	{ }
};
