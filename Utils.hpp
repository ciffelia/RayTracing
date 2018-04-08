#pragma once

#include <Siv3D.hpp>

namespace RayT {
	namespace Utils
	{
		// ���j�A��Ԃ���sRGB��Ԃ֕ϊ�
		constexpr ColorF LinearToGamma(const ColorF color, const double gammaFactor) {
			const double recipGammaFactor = 1 / gammaFactor;
			return {
				Math::Pow(color.r, recipGammaFactor),
				Math::Pow(color.g, recipGammaFactor),
				Math::Pow(color.b, recipGammaFactor)
			};
		}

		// sRGB��Ԃ��烊�j�A��Ԃ֕ϊ�
		constexpr ColorF GammaToLinear(const ColorF color, const double gammaFactor) {
			return {
				Math::Pow(color.r, gammaFactor),
				Math::Pow(color.g, gammaFactor),
				Math::Pow(color.b, gammaFactor)
			};
		}

		// �P�ʋ��̒��ɂ���x�N�g���������_���ɐ���
		inline Vec3 RandomVec3InUnitSphere()
		{
			while (true)
			{
				const Vec3 v = RandomVec3({ -1, 1 }, { -1, 1 }, { -1, 1 });
				if (v.length() <= 1)
					return v;
			}
		}
	}
}
