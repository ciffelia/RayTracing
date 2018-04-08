#pragma once

#include <Siv3D.hpp>

namespace RayT {
	struct Material;

	// �����ƕ��̂��Փ˂����Ƃ��̏��
	struct HitRec {
		// �����̃x�N�g���������̃p�����[�^
		double t;

		// �Փ˂����ʒu
		Vec3 p;

		// ���̂̏Փ˂����ʒu�̖@��
		Vec3 n;

		// ���̂̍ގ�
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
