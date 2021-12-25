#include <components/game/playerMovement.h>
#include <core/serviceHandler.h>
#include <systems/entitySystem.h>
#include <cmath>

void PlayerMovement::Start(Transform* parent)
{
	transform = parent;
	transform->tag = "Player";
	clock = ServiceHandler::instance->GetModule<Clock>();
	inputManager = ServiceHandler::instance->GetModule<InputHandler>();
	rb = ServiceHandler::instance->GetModule<EntitySystem>()->GetEntity(transform->ID)->GetComponent<Rigidbody>();
	cam = ServiceHandler::instance->GetModule<Camera>();
}

void PlayerMovement::Update()
{
	float thrustInput = inputManager->GetKey(SDLK_w) - inputManager->GetKey(SDLK_s);
	rb->AddForce(transform->Up() * thrustInput * speed * clock->GetDeltaTime());
	cam->MoveTo(transform->position + 16.0f); // 16.0f is half the scale (used to get centered position)
	int rotInput = inputManager->GetKey(SDLK_d) - inputManager->GetKey(SDLK_a);
	transform->rotation += rotInput * speed * clock->GetDeltaTime();
}