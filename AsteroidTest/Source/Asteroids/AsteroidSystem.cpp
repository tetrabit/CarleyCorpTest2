#include "AsteroidSystem.h"
#include <math.h>
#include <iostream>

void AsteroidSystem::intialize()
{
	// Add the initial four asteroids
	Asteroids.push_front(new Asteroid(-480.0, 230.0, 0, "Large"));
	Asteroids.push_front(new Asteroid(1540.0, 120.0, 0, "Large"));
	Asteroids.push_front(new Asteroid(620.0, -480.0, 0, "Large"));
	Asteroids.push_front(new Asteroid(-140.0, -950.0, 0, "Large"));
}

void AsteroidSystem::update(float delta_t)
{
	for (Asteroid* TheAsteroid : Asteroids)
	{
		TheAsteroid->updatePosition(delta_t);
	}

	TheColony->shootAtAsteroid(Asteroids);
}

void AsteroidSystem::printStats()
{
	for (Asteroid* TheAsteroid : Asteroids)
	{
		TheAsteroid->printStats();
	}

	if (Asteroids.size() > 0) std::cout << std::endl;
}

void AsteroidSystem::add(Asteroid* asteroid)
{
	Asteroids.push_front(asteroid);
}

void AsteroidSystem::remove(Asteroid* asteroid)
{
	Asteroids.erase(std::find(Asteroids.begin(), Asteroids.end(), asteroid));
}