#pragma once

#include <Siv3D.hpp>

#include "Material.hpp"
#include "Utils.hpp"

// 金属(鏡面反射)
struct Metal : Material {
	ColorF albedo;
	double fuzz;

	explicit Metal(const ColorF _albedo, const double _fuzz)
		: albedo(_albedo)
		, fuzz(_fuzz)
	{ }

	Optional<ScatterRec> scatter(const Ray ray, const HitRec hitRec) const override
	{
		// 反射
		const Vec3 refrected = Reflect(ray.direction, hitRec.n);

		// ずらす
		const Vec3 direction = (refrected + Utils::RandomVec3InUnitSphere() * fuzz).normalized();

		// 反射したベクトルと法線ベクトルのなす角が0°より小さいときは反射しない
		if (direction.dot(hitRec.n) <= 0)
			return none;

		const Ray newRay(hitRec.p, direction);

		return ScatterRec(newRay, albedo);
	}

	// nを法線ベクトルとする面で反射する
	static Vec3 Reflect(const Vec3 v, const Vec3 n) {
		return v - 2.f * v.dot(n) * n;
	}
};
