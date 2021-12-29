#pragma once
#include <core/component.h>
#include <systems/clock.h>
#include <components/rigidbody.h>

class BulletMovement : public Component
{
public:
	void Start(Transform* parent) override;
	void Update() override;
	float speed = 500.0f;

private:
	Transform* transform = nullptr;
	Clock* clock = nullptr;
	float maxLifeSpan = 1.5f;
	float lifeTime = 0.0f;
};