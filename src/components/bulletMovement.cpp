#include <components/bulletMovement.h>
#include <core/serviceHandler.h>
#include <systems/entitySystem.h>
#include <iostream>
void BulletMovement::Start(Transform* parent)
{
	transform = parent;
	clock = ServiceHandler::instance->GetModule<Clock>();
	maxLifeSpan = 1.0f;
	lifeTime = 0.0f;
}

void BulletMovement::Update()
{
	transform->position += transform->Up() * speed * clock->GetDeltaTime();
	std::cout << clock->GetDeltaTime() << std::endl;
	lifeTime += clock->GetDeltaTime();

	if (lifeTime > maxLifeSpan)
	{
		ServiceHandler::instance->GetModule<EntitySystem>()->DestroyEntity(transform->ID);
	}
}