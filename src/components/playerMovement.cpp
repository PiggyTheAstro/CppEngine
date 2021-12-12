#include <components/playerMovement.h>
#include <core/serviceHandler.h>

PlayerMovement::PlayerMovement()
{
	transform = nullptr;
	clock = nullptr;
	inputManager = nullptr;
	speed = 100.0f;
}

void PlayerMovement::Start(Transform* parent)
{
	transform = parent;
	clock = ServiceHandler::instance->GetModule<Clock>();
	inputManager = ServiceHandler::instance->GetModule<InputHandler>();
}

void PlayerMovement::Update()
{
	transform->position += transform->Down() * speed * clock->GetDeltaTime();
	int rawInput = inputManager->GetKey(SDLK_d) - inputManager->GetKey(SDLK_a);
	transform->rotation += rawInput * speed * clock->GetDeltaTime();
}