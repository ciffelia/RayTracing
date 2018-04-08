#pragma once

#include <Siv3D.hpp>

#include "Material.hpp"

// ����(���ʔ���)
struct Metal : Material {
	ColorF albedo;

	explicit Metal(const ColorF _albedo)
		: albedo(_albedo)
	{ }

	Optional<ScatterRec> scatter(const Ray ray, const HitRec hitRec) const override
	{
		const Ray newRay(hitRec.p, Reflect(ray.direction, hitRec.n));
		const ScatterRec scratterRec(newRay, albedo);

		return
			newRay.direction.dot(hitRec.n) > 0
			? make_Optional(scratterRec)
			: none;
	}

	// n��@���x�N�g���Ƃ���ʂŔ��˂���
	static Vec3 Reflect(const Vec3 v, const Vec3 n) {
		return v - 2.f * v.dot(n) * n;
	}
};
