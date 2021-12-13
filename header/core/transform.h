#pragma once
#include <Math/vectors.h>

class Transform
{
public:
	Transform(unsigned int identifier);
	Vectors::Vector2 Up();
	Vectors::Vector2 Down();
	Vectors::Vector2 Left();
	Vectors::Vector2 Right();

	unsigned int ID;
	Vectors::Vector2 position;
	float rotation;
	Vectors::Vector2 scale;
};