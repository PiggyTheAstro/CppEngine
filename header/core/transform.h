#pragma once
#include <Math/vectors.h>

class Transform
{
public:
	Transform();
	Vectors::Vector2 Up();
	Vectors::Vector2 Down();
	Vectors::Vector2 Left();
	Vectors::Vector2 Right();

	Vectors::Vector2 position;
	float rotation;
	Vectors::Vector2 scale;
};