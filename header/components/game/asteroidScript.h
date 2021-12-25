#pragma once
#include <core/component.h>
#include <systems/clock.h>
#include <components/rectCollider.h>

class AsteroidScript : public Component
{
public:
	void Start(Transform* parent) override;
	void Update() override;
	void SetPlayer(Transform* playerTransform);
	void OnCollisionEnter();

private:
	float health;
	Transform* transform = nullptr;
	Transform* player = nullptr;
	Clock* clock = nullptr;
	RectCollider* collider = nullptr;
	float speed;
};