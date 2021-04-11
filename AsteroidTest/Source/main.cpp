#include "Asteroids/AsteroidSystem.h"
#include <iostream>

int main()
{
	AsteroidSystem TheAsteroids;

	TheAsteroids.intialize();

	for (unsigned int i = 0; i < 100; ++i)
	{
		TheAsteroids.printStats();
		TheAsteroids.update(1.0f);
	}

	std::cout << "Remaining asteroids = " << TheAsteroids.getRemainingAsteroids() << std::endl;
	TheAsteroids.printStats();

	return 0;
}