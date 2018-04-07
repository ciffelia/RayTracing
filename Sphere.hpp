#pragma once

#include <Siv3D.hpp>

struct Material;

// ‹…
struct Sphere
{
	// ’†S
	Vec3 center;

	// ”¼Œa
	double r;

	// Ş¿
	std::shared_ptr<Material> materialPtr;

	Sphere() = default;

	Sphere(const Vec3 _center, const double _r, const std::shared_ptr<Material> _materialPtr)
		: center(_center)
		, r(_r)
		, materialPtr(_materialPtr)
	{ }
};
