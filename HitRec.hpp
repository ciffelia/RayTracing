#pragma once

#include <Siv3D.hpp>

// 光線と物体が衝突したときの情報
struct HitRec {
	// 光線のベクトル方程式のパラメータ
	double t;

	// 衝突した位置
	Vec3 p;

	// 物体の衝突した位置の法線
	Vec3 n;

	HitRec() = default;

	constexpr HitRec(const double _t, const Vec3 _p, const Vec3 _n)
		: t(_t)
		, p(_p)
		, n(_n)
	{ }
};
