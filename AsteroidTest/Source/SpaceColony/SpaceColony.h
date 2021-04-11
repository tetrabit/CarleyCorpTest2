#pragma once
#include "..\Asteroids\Asteroid.h"
#include "..\LaserCannon\LaserCannon.h"
#include "..\RandomNumber.h"
#include <deque>

class SpaceColony
{
public:
	SpaceColony(float x, float y);
	~SpaceColony();

	void shootAtAsteroid(std::deque<Asteroid*> asteroids);

private:
	float PositionX;
	float PositionY;
	LaserCannon* TheCannon;
	RandomNumber RandomHit;
	RandomNumber RandomOffset;
};