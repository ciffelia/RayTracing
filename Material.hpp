#pragma once

#include <Siv3D.hpp>

#include "Ray.hpp"
#include "HitRec.hpp"
#include "ScatterRec.hpp"

// �ގ�
struct Material
{
	Material() = default;

	// ���ˁE�U���̌v�Z
	// �U������ꍇ�͂��̏����A�U�����Ȃ��ꍇ��none��Ԃ�
	virtual Optional<ScatterRec> scatter(const Ray ray, const HitRec hitRec) const
	{
		return none;
	}
};
