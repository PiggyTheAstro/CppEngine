#pragma once
#include <core/component.h>
#include <systems/clock.h>
#include <systems/inputHandler.h>
#include <systems/entitySystem.h>

class PlayerShooting : public Component
{
public:
	void Start(Transform* parent) override;
	void Update() override;
	void Shoot();
	void ResetFire();

private:
	Clock* clock = nullptr;
	InputHandler* input = nullptr;
	EntitySystem* entSys = nullptr;
	Transform* transform = nullptr;
	float fireRate = 1.0f;
	bool canShoot = true;
};