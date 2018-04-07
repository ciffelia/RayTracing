#pragma once

#include <Siv3D.hpp>

#include "Ray.hpp"
#include "HitRec.hpp"
#include "ScatterRec.hpp"

// Ş¿
struct Material
{
	Material() = default;

	// ”½ËEU—‚ÌŒvZ
	// U—‚·‚éê‡‚Í‚»‚Ìî•ñ‚ğAU—‚µ‚È‚¢ê‡‚Ínone‚ğ•Ô‚·
	virtual Optional<ScatterRec> scatter(const Ray ray, const HitRec hitRec) const
	{
		return none;
	}
};
