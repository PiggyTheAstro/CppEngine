#include <components/game/playerShooting.h>
#include <core/serviceHandler.h>
#include <iostream>
#include <components/rectRenderer.h>
#include <components/game/bulletMovement.h>

void PlayerShooting::Start(Transform* parent)
{
	transform = parent;
	clock = ServiceHandler::instance->GetModule<Clock>();
	input = ServiceHandler::instance->GetModule<InputHandler>();
	entSys = ServiceHandler::instance->GetModule<EntitySystem>();
}

void PlayerShooting::Update()
{
	if (!canShoot)
	{
		if (cooldown < fireRate) 
		{
			cooldown += clock->GetDeltaTime();
		}
		else 
		{
			canShoot = true;
		}
		return;
	}
	else if(input->GetKey(SDLK_SPACE))
	{
		Shoot();
	}
}

void PlayerShooting::Shoot()
{
	Entity* bullet = entSys->CreateEntity();
	bullet->transform.position = transform->position + (transform->scale / 3.0f);
	bullet->transform.rotation = transform->rotation;
	bullet->transform.scale = Vectors::Vector2(8.0f, 8.0f);
	bullet->AddComponent<RectRenderer>();
	bullet->AddComponent<BulletMovement>();
	bullet->GetComponent<BulletMovement>()->speed += entSys->GetEntity(transform->ID)->GetComponent<Rigidbody>()->velocity.Magnitude() / 0.02f;;
	canShoot = false;
	cooldown = 0.0f;
}