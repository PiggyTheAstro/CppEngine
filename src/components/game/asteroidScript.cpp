#include <components/game/asteroidScript.h>
#include <Math/random.h>
#include <core/serviceHandler.h>
#include <functional>
#include <components/game/playerShooting.h>

void AsteroidScript::Start(Transform* parent)
{
	transform = parent;
	transform->tag = "Asteroid";
	transform->rotation = Random::Rand(0.0f, 360.0f);
	transform->scale = Vectors::Vector2(30.0f, 30.0f) * Random::Rand(1.0f, 2.0f);
	speed = Random::Rand(50.0f, 70.0f);
	health = Random::Randint(1, 4);
	clock = ServiceHandler::instance->GetModule<Clock>();
	entSys = ServiceHandler::instance->GetModule<EntitySystem>();
	collider = entSys->GetEntity(transform->ID)->GetComponent<RectCollider>();
	collider->AddListener(std::bind(&AsteroidScript::OnCollisionEnter, this), nullptr);
}

void AsteroidScript::Update()
{
	transform->position += transform->Up() * speed * clock->GetDeltaTime();
	if ((transform->position - player->position).Magnitude() > 2500.0f)
	{
		ServiceHandler::instance->GetModule<EntitySystem>()->DestroyEntity(transform->ID);
	}
}

void AsteroidScript::SetPlayer(Transform* playerTransform)
{
	player = playerTransform;
}

void AsteroidScript::OnCollisionEnter()
{
	if (collider->col->tag == "Player")
	{
		ServiceHandler::instance->isRunning = false;
	}

	if (collider->col->tag == "PlayerBullet") 
	{
		health -= 1;
		entSys->DestroyEntity(collider->col->ID);
	}
	if(health <= 0)
	{
		if (entSys->GetEntity(player->ID)->GetComponent<PlayerShooting>()->fireRate > 0.1f)
		{
			entSys->GetEntity(player->ID)->GetComponent<PlayerShooting>()->fireRate -= 0.05f;
		}
		entSys->DestroyEntity(transform->ID);
	}
}

