#pragma once
#include <core/component.h>
#include <systems/inputHandler.h>
#include <systems/clock.h>
#include <components/rigidbody.h>
#include <systems/camera.h>

class PlayerMovement : public Component
{
public:
	void Start(Transform* parent) override;
	void Update() override;
private:
	Transform* transform = nullptr;
	InputHandler* inputManager = nullptr;
	Clock* clock = nullptr;
	Rigidbody* rb = nullptr;
	Camera* cam = nullptr;
	float speed = 200.0f;
};