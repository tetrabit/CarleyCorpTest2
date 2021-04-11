#pragma once
#include <string>

class Asteroid
{
public:
	Asteroid(float px, float py, char size, std::string size_name);
	~Asteroid();

	void updatePosition(float delta_t);
	void printStats();
	float getPositionX() { return PositionX; }
	float getPositionY() { return PositionY; }
	float getVelocityX() { return VelocityX; }
	float getVelocityY() { return VelocityY; }
	char getSize() { return Size; }
	std::string getSizeName() { return SizeName; }

private:

	char Size; // 0 = Large, 1 = Medium, 2 = Small

	// Positions in kilometers
	float PositionX;
	float PositionY;

	// Large, Medium, Small
	std::string SizeName;

	// Velocities in kilometers/second
	float VelocityX;
	float VelocityY;
};