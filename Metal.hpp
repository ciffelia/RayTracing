#pragma once

#include <Siv3D.hpp>

#include "Material.hpp"
#include "Utils.hpp"

// ����(���ʔ���)
struct Metal : Material {
	ColorF albedo;
	double fuzz;

	explicit Metal(const ColorF _albedo, const double _fuzz)
		: albedo(_albedo)
		, fuzz(_fuzz)
	{ }

	Optional<ScatterRec> scatter(const Ray ray, const HitRec hitRec) const override
	{
		// ����
		const Vec3 refrected = Reflect(ray.direction, hitRec.n);

		// ���炷
		const Vec3 direction = (refrected + Utils::RandomVec3InUnitSphere() * fuzz).normalized();

		// ���˂����x�N�g���Ɩ@���x�N�g���̂Ȃ��p��0����菬�����Ƃ��͔��˂��Ȃ�
		if (direction.dot(hitRec.n) <= 0)
			return none;

		const Ray newRay(hitRec.p, direction);

		return ScatterRec(newRay, albedo);
	}

	// n��@���x�N�g���Ƃ���ʂŔ��˂���
	static Vec3 Reflect(const Vec3 v, const Vec3 n) {
		return v - 2.f * v.dot(n) * n;
	}
};
