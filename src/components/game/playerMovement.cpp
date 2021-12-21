#include <components/game/playerMovement.h>
#include <core/serviceHandler.h>
#include <systems/entitySystem.h>
#include <cmath>

void PlayerMovement::Start(Transform* parent)
{
	transform = parent;
	clock = ServiceHandler::instance->GetModule<Clock>();
	inputManager = ServiceHandler::instance->GetModule<InputHandler>();
	rb = ServiceHandler::instance->GetModule<EntitySystem>()->GetEntity(transform->ID)->GetComponent<Rigidbody>();
	cam = ServiceHandler::instance->GetModule<Camera>();
}

void PlayerMovement::Update()
{
	float thrustInput = inputManager->GetKey(SDLK_w) - inputManager->GetKey(SDLK_s);
	rb->AddForce(transform->Up() * thrustInput * speed * clock->GetDeltaTime());
	cam->position = transform->position - Vectors::Vector2(275.0f - 16.0f, 375.0f + 16.0f);
	int rotInput = inputManager->GetKey(SDLK_d) - inputManager->GetKey(SDLK_a);
	transform->rotation += rotInput * speed * clock->GetDeltaTime();
}