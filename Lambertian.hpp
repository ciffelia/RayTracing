#pragma once

#include <Siv3D.hpp>

#include "Material.hpp"
#include "Utils.hpp"

// �����o�[�g(�g�U����)
struct Lambertian : Material {
	ColorF albedo;

	explicit Lambertian(const ColorF _albedo)
		: albedo(_albedo)
	{ }

	Optional<ScatterRec> scatter(const Ray ray, const HitRec hitRec) const override
	{
		const Ray newRay(hitRec.p, hitRec.n + Utils::RandomVec3InUnitSphere());

		return ScatterRec(newRay, albedo);
	}
};
