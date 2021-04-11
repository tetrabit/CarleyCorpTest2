#include "Asteroid.h"
#include <math.h>
#include <iostream>

Asteroid::Asteroid(float px, float py, char size, std::string size_name)
{
	PositionX = px;
	PositionY = py;

	switch (size)
	{
	case 0:
	{
		float Angle = tanf(py / px);
		VelocityX = -10.0f * sinf(Angle);
		VelocityY = -10.0f * cosf(Angle);
		Size = 0;
		SizeName = "Large";

		break;
	}
	case 1:
	{
		float Angle = tanf(py / px);
		VelocityX = 20.0f * cosf(Angle);
		VelocityY = 20.0f * sinf(Angle);
		Size = 1;
		SizeName = "Medium";

		break;
	}
	case 2:
	{
		float Angle = tanf(px / py);
		VelocityX = -40.0f * cosf(Angle);
		VelocityY = -40.0f * sinf(Angle);
		Size = 2;
		SizeName = "Small";

		break;
	}
	}
}

Asteroid::~Asteroid()
{

}

void Asteroid::updatePosition(float delta_t)
{
	PositionX = PositionX + (VelocityX * delta_t);
	PositionY = PositionY + (VelocityY * delta_t);
}

void Asteroid::printStats()
{
	std::cout << "Asteroid = " << SizeName << ", Position(" << PositionX << ", " << PositionY << "), Velocity(" << VelocityX << ", " << VelocityY << ")" << std::endl;
}