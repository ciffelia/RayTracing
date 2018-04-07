#pragma once

#include <Siv3D.hpp>

// �����ƕ��̂��Փ˂����Ƃ��̏��
struct HitRec {
	// �����̃x�N�g���������̃p�����[�^
	double t;

	// �Փ˂����ʒu
	Vec3 p;

	// ���̂̏Փ˂����ʒu�̖@��
	Vec3 n;

	HitRec() = default;

	constexpr HitRec(const double _t, const Vec3 _p, const Vec3 _n)
		: t(_t)
		, p(_p)
		, n(_n)
	{ }
};
