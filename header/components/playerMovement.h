#pragma once
#include <core/component.h>
#include <systems/inputHandler.h>
#include <systems/clock.h>

class PlayerMovement : public Component
{
public:
	PlayerMovement();
	void Start(Transform* parent) override;
	void Update() override;

private:
	Transform* transform;
	InputHandler* inputManager;
	Clock* clock;
	float speed;
};