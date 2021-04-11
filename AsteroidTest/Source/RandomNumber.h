#pragma once

#include <random>

class RandomNumber
{
public:
	RandomNumber(float min, float max) : Distribution(min, max)
	{
		std::random_device RandomDevice;
		Generator.seed(RandomDevice());
	}

	~RandomNumber() {};

	inline float getNumber()
	{
		return static_cast<float>(Distribution(Generator));
	}

private:
	std::mt19937 Generator;
	std::uniform_real_distribution<> Distribution;
};
