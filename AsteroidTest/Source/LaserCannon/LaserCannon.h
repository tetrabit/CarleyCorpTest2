#pragma once
#include <string>

class LaserCannon
{
public:
	LaserCannon();
	~LaserCannon();

	float getHitProbability(std::string asteroid_size);

private:
	float LargeHitProbability;
	float MediumHitProbability;
	float SmallHitProbability;
};