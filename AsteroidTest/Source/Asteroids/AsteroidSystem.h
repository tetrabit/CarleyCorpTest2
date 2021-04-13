#pragma once

#include "..//RandomNumber.h"
#include "Asteroid.h"
#include "..\SpaceColony\SpaceColony.h"
#include <string>
#include <deque>

class AsteroidSystem
{
	static AsteroidSystem* instance;

public:
	static AsteroidSystem* getInstance() {
		if (!instance)
			instance = new AsteroidSystem;
		return instance;
	}

	AsteroidSystem() { TheColony = new SpaceColony(0.0f, 0.0f); }
	~AsteroidSystem() {};

	void intialize();
	void update(float delta_t);
	unsigned int getRemainingAsteroids() { return static_cast<int>(Asteroids.size()); }
	void printStats();
	void add(Asteroid* asteroid);
	void remove(Asteroid* asteroid);

private:
	std::deque<Asteroid*> Asteroids;
	SpaceColony* TheColony;
};