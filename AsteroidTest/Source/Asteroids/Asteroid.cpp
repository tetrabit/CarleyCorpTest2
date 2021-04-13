#include "Asteroid.h"
#include <math.h>
#include <iostream>

float* normalizeVector(float PosX, float PosY)
{
	static float vector[2];
	double length = sqrt(pow(PosX, 2) + pow(PosY, 2));
	vector[0] = PosX / (float)length;
	vector[1] = PosY / (float)length;
	return vector;
}

Asteroid::Asteroid(float px, float py, char size, std::string size_name)
{
	PositionX = px;
	PositionY = py;
	VelocityX = 0;
	VelocityY = 0;
	Size = 0;

	switch (size)
	{
		case 0:
		{
			VelocityX = -normalizeVector(px, py)[0] * 10.0f;
			VelocityY = -normalizeVector(px, py)[1] * 10.0f;
			Size = 0;
			SizeName = "Large";

			break;
		}
		case 1:
		{
			VelocityX = -normalizeVector(px, py)[0] * 20.0f;
			VelocityY = -normalizeVector(px, py)[1] * 20.0f;
			Size = 1;
			SizeName = "Medium";

			break;
		}
		case 2:
		{
			VelocityX = -normalizeVector(px, py)[0] * 40.0f;
			VelocityY = -normalizeVector(px, py)[1] * 40.0f;
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
	updateVelocity();
	PositionX = PositionX + (VelocityX * delta_t);
	PositionY = PositionY + (VelocityY * delta_t);
}

void Asteroid::updateVelocity()
{
	switch (Size)
	{
		case 0:
		{
			VelocityX = -normalizeVector(PositionX, PositionY)[0] * 10.0f;
			VelocityY = -normalizeVector(PositionX, PositionY)[1] * 10.0f;

			Size = 0;
			SizeName = "Large";

			break;
		}
		case 1:
		{
			VelocityX = -normalizeVector(PositionX, PositionY)[0] * 20.0f;
			VelocityY = -normalizeVector(PositionX, PositionY)[1] * 20.0f;
			Size = 1;
			SizeName = "Medium";

			break;
		}
		case 2:
		{
			VelocityX = -normalizeVector(PositionX, PositionY)[0] * 40.0f;
			VelocityY = -normalizeVector(PositionX, PositionY)[1] * 40.0f;
			Size = 2;
			SizeName = "Small";

			break;
		}
	}
}

void Asteroid::printStats()
{
	std::cout << "Asteroid = " << SizeName << ", Position(" << PositionX << ", " << PositionY << "), Velocity(" << VelocityX << ", " << VelocityY << ")" << std::endl;
}