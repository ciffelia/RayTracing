#pragma once

namespace Constants
{
#ifdef _DEBUG
	constexpr int Samples = 3;
#else
	constexpr int Samples = 100;
#endif

	constexpr double GammaValue = 2.2;
}
