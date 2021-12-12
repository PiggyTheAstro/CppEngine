#include <core/transform.h>

Transform::Transform()
{
	position = Vectors::Vector2(0.0f, 0.0f);
	rotation = 0.0f;
	scale = Vectors::Vector2(1.0f, 1.0f);
}

Vectors::Vector2 Transform::Down()
{
	Vectors::Vector2 globalDown = Vectors::Vector2(0.0f, 1.0f);
	globalDown.Rotate(rotation);
	return globalDown;
}