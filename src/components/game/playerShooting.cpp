#include <components/game/playerShooting.h>
#include <core/serviceHandler.h>
#include <components/spriteRenderer.h>
#include <components/game/bulletMovement.h>
#include <components/rectCollider.h>
#include <functional>

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
		return;
	}
	else if(input->GetKey(SDLK_SPACE))
	{
		Shoot();
	}
}

void PlayerShooting::Shoot()
{
	canShoot = false;
	Entity* bullet = entSys->CreateEntity();
	bullet->transform.position = transform->position + (transform->scale / 3.0f);
	bullet->transform.rotation = transform->rotation;
	bullet->transform.scale = Vectors::Vector2(12.0f, 12.0f);
	bullet->AddComponent<SpriteRenderer>();
	bullet->GetComponent<SpriteRenderer>()->SetSprite("resources/bullet.bmp");
	bullet->AddComponent<RectCollider>();
	bullet->AddComponent<BulletMovement>();
	bullet->GetComponent<BulletMovement>()->speed += entSys->GetEntity(transform->ID)->GetComponent<Rigidbody>()->velocity.Magnitude() / 0.02f;;
	clock->StartTimer(std::bind(&PlayerShooting::ResetFire, this), fireRate);
}

void PlayerShooting::ResetFire()
{
	canShoot = true;
}