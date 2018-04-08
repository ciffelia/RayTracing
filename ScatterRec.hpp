#pragma once

#include <Siv3D.hpp>

#include "Ray.hpp"

namespace RayT {
	// �U���̏��
	struct ScatterRec
	{
		// �U����̐V��������
		Ray ray;

		// ���˗�
		ColorF albedo;

		constexpr ScatterRec(const Ray _ray, const ColorF _albedo)
			: ray(_ray)
			, albedo(_albedo)
		{ }
	};
}
