#pragma once
#include <core/subsystem.h>
#include <Math/vectors.h>

class Camera : public SubSystem
{
public:
	Vectors::Vector2 position;
};