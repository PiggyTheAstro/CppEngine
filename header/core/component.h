#pragma once
#include <core/transform.h>
class Component
{
public:
	//virtual void Start(Vectors::Vector2* parentPos, Vectors::Vector2* parentSca) = 0;
	virtual void Start(Transform* parent) = 0;
	virtual void Update() = 0;
};