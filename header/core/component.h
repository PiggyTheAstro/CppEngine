#pragma once
#include <core/transform.h>
class Component
{
public:
	virtual void Start(Transform* parent) = 0;
	virtual void Update() = 0;
};