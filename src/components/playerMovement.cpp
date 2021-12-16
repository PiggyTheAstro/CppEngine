#include <components/playerMovement.h>
#include <core/serviceHandler.h>
#include <systems/entitySystem.h>

void PlayerMovement::Start(Transform* parent)
{
	transform = parent;
	clock = ServiceHandler::instance->GetModule<Clock>();
	inputManager = ServiceHandler::instance->GetModule<InputHandler>();
	rb = ServiceHandler::instance->GetModule<EntitySystem>()->GetEntity(transform->ID)->GetComponent<Rigidbody>();
}

void PlayerMovement::Update()
{
	float thrustInput = inputManager->GetKey(SDLK_w) - inputManager->GetKey(SDLK_s);
	rb->AddForce(transform->Up() * thrustInput * speed * clock->GetDeltaTime());
	int rotInput = inputManager->GetKey(SDLK_d) - inputManager->GetKey(SDLK_a);
	transform->rotation += rotInput * speed * clock->GetDeltaTime();
}