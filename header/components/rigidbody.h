#pragma once
#include <core/component.h>
#include <Math/vectors.h>
#include <systems/clock.h>

class Rigidbody : public Component
{
public:
	void Start(Transform* parent) override;
	void Update() override;
	void AddForce(Vectors::Vector2 vector);
private:
	Clock* clock;
	float mass = 100.0f;
	float friction = 0.5f;
	Vectors::Vector2 velocity;
	Transform* transform = nullptr;
};