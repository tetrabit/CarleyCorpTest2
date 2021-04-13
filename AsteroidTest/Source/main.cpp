#include "Asteroids/AsteroidSystem.h"
#include <iostream>

AsteroidSystem* AsteroidSystem::instance = 0;

int main()
{
	AsteroidSystem *TheAsteroids = TheAsteroids->getInstance();

	TheAsteroids->intialize();

	while (TheAsteroids->getRemainingAsteroids() > 0)
	{
		TheAsteroids->printStats();
		TheAsteroids->update(1.0f);
	}

	std::cout << "Remaining asteroids = " << TheAsteroids->getRemainingAsteroids() << std::endl;
	TheAsteroids->printStats();

	return 0;
}