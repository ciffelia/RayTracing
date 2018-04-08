#pragma once

#include <Siv3D.hpp>

namespace RayT {
	namespace Utils
	{
		// リニア空間からsRGB空間へ変換
		constexpr ColorF LinearToGamma(const ColorF color, const double gammaFactor) {
			const double recipGammaFactor = 1 / gammaFactor;
			return {
				Math::Pow(color.r, recipGammaFactor),
				Math::Pow(color.g, recipGammaFactor),
				Math::Pow(color.b, recipGammaFactor)
			};
		}

		// sRGB空間からリニア空間へ変換
		constexpr ColorF GammaToLinear(const ColorF color, const double gammaFactor) {
			return {
				Math::Pow(color.r, gammaFactor),
				Math::Pow(color.g, gammaFactor),
				Math::Pow(color.b, gammaFactor)
			};
		}

		// 単位球の中にあるベクトルをランダムに生成
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
