#pragma once
#include <core/component.h>
#include <systems/clock.h>
#include <components/rectCollider.h>
#include <components/rigidbody.h>
#include <systems/entitySystem.h>

class SeekerScript : public Component
{
public:
	void Start(Transform* parent) override;
	void Update() override;
	void SetPlayer(Transform* playerTransform);
	void OnCollisionEnter();
	float health;
	float speed;

private:
	Transform* transform = nullptr;
	Transform* player = nullptr;
	Clock* clock = nullptr;
	RectCollider* collider = nullptr;
	Rigidbody* rb = nullptr;
	EntitySystem* entSys = nullptr;
};