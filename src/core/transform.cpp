#include <core/transform.h>

Transform::Transform()
{
	position = Vectors::Vector2(0.0f, 0.0f);
	rotation = 0.0f;
	scale = Vectors::Vector2(1.0f, 1.0f);
}

Vectors::Vector2 Transform::Up()
{
	Vectors::Vector2 globalUp = Vectors::Vector2(0.0f, -1.0f);
	return globalUp.Rotate(rotation);
}

Vectors::Vector2 Transform::Down()
{
	Vectors::Vector2 globalDown = Vectors::Vector2(0.0f, 1.0f);
	return globalDown.Rotate(rotation);
}

Vectors::Vector2 Transform::Left()
{
	Vectors::Vector2 globalLeft = Vectors::Vector2(-1.0f, 0.0f);
	return globalLeft.Rotate(rotation);
}

Vectors::Vector2 Transform::Right()
{
	Vectors::Vector2 globalRight = Vectors::Vector2(1.0f, 0.0f);
	return globalRight.Rotate(rotation);
}