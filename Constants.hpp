#pragma once

namespace RayT {
	namespace Constants
	{
		constexpr int Samples = SIV3D_IS_DEBUG ? 3 : 100;

		constexpr int MaxRecurse = 50;

		constexpr double GammaValue = 2.2;
	}
}
