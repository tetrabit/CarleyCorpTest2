#include "LaserCannon.h"

LaserCannon::LaserCannon()
{
	LargeHitProbability = 0.8f;
	MediumHitProbability = 0.6f;
	SmallHitProbability = 0.5f;
}

LaserCannon::~LaserCannon()
{

}

float LaserCannon::getHitProbability(std::string asteroid_size)
{
	if (asteroid_size == "Large")
	{
		return LargeHitProbability;
	}
	else if (asteroid_size == "Medium")
	{
		return MediumHitProbability;
	}
	else if (asteroid_size == "Small")
	{
		return SmallHitProbability;
	}
}