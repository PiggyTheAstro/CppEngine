#pragma once
#include <core/component.h>
#include <systems/inputHandler.h>
#include <systems/clock.h>

class PlayerMovement : public Component
{
public:
	void Start(Transform* parent) override;
	void Update() override;

private:
	Transform* transform = nullptr;
	InputHandler* inputManager = nullptr;
	Clock* clock = nullptr;
	float speed = 100.0f;
};