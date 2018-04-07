#pragma once

#include <Siv3D.hpp>

#include "Material.hpp"

// �����o�[�g(�g�U����)
struct Lambertian : Material {
	ColorF albedo;

	explicit Lambertian(const ColorF _albedo)
		: albedo(_albedo)
	{ }

	Optional<ScatterRec> scatter(const Ray ray, const HitRec hitRec) const override
	{
		const Ray newRay(hitRec.p, hitRec.n + RandomVec3());

		return ScatterRec(newRay, albedo);
	}
};
