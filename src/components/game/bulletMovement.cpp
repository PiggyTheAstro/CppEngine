#include <components/game/bulletMovement.h>
#include <core/serviceHandler.h>
#include <systems/entitySystem.h>

void BulletMovement::Start(Transform* parent)
{
	transform = parent;
	transform->tag = "PlayerBullet";
	clock = ServiceHandler::instance->GetModule<Clock>();
	maxLifeSpan = 3.0f;
	lifeTime = 0.0f;
}

void BulletMovement::Update()
{
	transform->position += transform->Up() * speed * clock->GetDeltaTime();
	lifeTime += clock->GetDeltaTime();
	if (lifeTime > maxLifeSpan)
	{
		ServiceHandler::instance->GetModule<EntitySystem>()->DestroyEntity(transform->ID);
	}
}