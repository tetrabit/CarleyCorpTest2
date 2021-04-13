#include "SpaceColony.h"
#include "../Asteroids/AsteroidSystem.h"
#include <iostream>
#include <deque>

SpaceColony::SpaceColony(float x, float y) : RandomHit(0.0f, 1.0f), RandomOffset(-10.0f, 10.0f)
{
	TheCannon = new LaserCannon();
	PositionX = x;
	PositionY = y;
}

SpaceColony::~SpaceColony()
{
}

void SpaceColony::shootAtAsteroid(std::deque<Asteroid*> asteroids)
{
	AsteroidSystem* asteroidSystem = asteroidSystem->getInstance();
	Asteroid *TargetAsteroid = nullptr;
	float MinDistance = 1000000.0f; // Just a really big dumb number
	float ClosestDistance = 0.0f;

	for (Asteroid* TheAsteroid : asteroids)
	{
		// Calculate the square of the distance
		ClosestDistance = sqrtf(powf(TheAsteroid->getPositionX(), 2.0f) + powf(TheAsteroid->getPositionY(), 2.0f));

		// Check to see if this asteroid is the closest
		if (ClosestDistance < MinDistance)
		{
			TargetAsteroid = TheAsteroid;
			MinDistance = ClosestDistance;
		}
		//check to see if there is a tie for distance, if there is take the faster asteroid
		else if (ClosestDistance == MinDistance)
		{
			float targetAsteroidVelocity = sqrtf(powf(TheAsteroid->getVelocityX(), 2.0f) + powf(TheAsteroid->getVelocityY(), 2.0f));
			float theAsteroidVelocity = sqrtf(powf(TheAsteroid->getVelocityX(), 2.0f) + powf(TheAsteroid->getVelocityY(), 2.0f));
			if (targetAsteroidVelocity < targetAsteroidVelocity)
			{
				TargetAsteroid = TheAsteroid;
				MinDistance = ClosestDistance;
			}
		}
	}

	// Shoot at the asteroid
	switch (TargetAsteroid->getSize())
	{
		case 0:
		{
			std::cout << "----- Shooting at a Large Asteroid -----" << std::endl;
			if (RandomHit.getNumber() <= TheCannon->getHitProbability(TargetAsteroid->getSizeName()))
			{
				std::cout << "+++++ Large asteroid has been hit! +++++" << std::endl << std::endl;

				// Split the asteroid into two Medium ones
				asteroidSystem->add(new Asteroid((TargetAsteroid->getPositionX() + RandomOffset.getNumber()), (TargetAsteroid->getPositionY() + RandomOffset.getNumber()), 1, "Medium"));
				asteroidSystem->add(new Asteroid((TargetAsteroid->getPositionX() + RandomOffset.getNumber()), (TargetAsteroid->getPositionY() + RandomOffset.getNumber()), 1, "Medium"));
				asteroidSystem->remove(TargetAsteroid);
			}
			else
			{
				std::cout << "***** Missed Large asteroid!!! *****" << std::endl << std::endl;
			}
			break;
		}
		case 1:
		{
			std::cout << "----- Shooting at a Medium Asteroid -----" << std::endl;
			if (RandomHit.getNumber() <= TheCannon->getHitProbability(TargetAsteroid->getSizeName()))
			{
				std::cout << "+++++ Medium asteroid has been hit! +++++" << std::endl << std::endl;

				// Split the asteroid into two Small ones
				asteroidSystem->add(new Asteroid((TargetAsteroid->getPositionX() + RandomOffset.getNumber()), (TargetAsteroid->getPositionY() + RandomOffset.getNumber()), 2, "Small"));
				asteroidSystem->add(new Asteroid((TargetAsteroid->getPositionX() + RandomOffset.getNumber()), (TargetAsteroid->getPositionY() + RandomOffset.getNumber()), 2, "Small"));
				asteroidSystem->remove(TargetAsteroid);
			}
			else
			{
				std::cout << "***** Missed Medium asteroid!!! *****" << std::endl << std::endl;
			}
			break;
		}
		case 2:
		{
			std::cout << "----- Shooting at a Small Asteroid -----" << std::endl;
			if (RandomHit.getNumber() <= TheCannon->getHitProbability(TargetAsteroid->getSizeName()))
			{
				std::cout << "+++++ Small asteroid has been hit! +++++" << std::endl << std::endl;
				asteroidSystem->remove(TargetAsteroid);
			}
			else
			{
				std::cout << "***** Missed Small asteroid!!! *****" << std::endl << std::endl;
			}
			break;
		}
	}

	std::cout << asteroids.size() << " asteroids left." << std::endl << std::endl;
}