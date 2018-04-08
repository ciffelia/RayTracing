#pragma once

#include <Siv3D.hpp>

namespace ColorUtil
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

	// リニア空間からsRGB空間へ変換
	constexpr ColorF GammaToLinear(const ColorF color, const double gammaFactor) {
		return {
			Math::Pow(color.r, gammaFactor),
			Math::Pow(color.g, gammaFactor),
			Math::Pow(color.b, gammaFactor)
		};
	}
}
