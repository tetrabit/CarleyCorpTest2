#pragma once

#include "..//RandomNumber.h"
#include "Asteroid.h"
#include "..\SpaceColony\SpaceColony.h"
#include <string>
#include <deque>

class AsteroidSystem
{
public:
	AsteroidSystem() { TheColony = new SpaceColony(0.0f, 0.0f); }
	~AsteroidSystem() {};

	void intialize();
	void update(float delta_t);
	unsigned int getRemainingAsteroids() { return Asteroids.size(); }
	void printStats();

private:
	std::deque<Asteroid*> Asteroids;
	SpaceColony* TheColony;
};