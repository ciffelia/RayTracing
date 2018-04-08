#pragma once

#include <Siv3D.hpp>

namespace RayT {
	struct Material;

	// 光線と物体が衝突したときの情報
	struct HitRec {
		// 光線のベクトル方程式のパラメータ
		double t;

		// 衝突した位置
		Vec3 p;

		// 物体の衝突した位置の法線
		Vec3 n;

		// 物体の材質
		std::shared_ptr<Material> materialPtr;

		HitRec() = default;

		HitRec(const double _t, const Vec3 _p, const Vec3 _n, const std::shared_ptr<Material> _materialPtr)
			: t(_t)
			, p(_p)
			, n(_n)
			, materialPtr(_materialPtr)
		{ }
	};
}
