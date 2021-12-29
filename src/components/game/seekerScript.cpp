#include <components/game/seekerScript.h>
#include <Math/random.h>
#include <core/serviceHandler.h>
#include <components/game/playerShooting.h>
#include <functional>
#include <cmath>
#define PI 3.14159265358979323846f

void SeekerScript::Start(Transform* parent)
{
	transform = parent;
	transform->tag = "Seeker";
	transform->scale = Vectors::Vector2(42.0f, 42.0f);
	speed = Random::Rand(200.0f, 250.0f);
	health = Random::Randint(2, 3);
	clock = ServiceHandler::instance->GetModule<Clock>();
	entSys = ServiceHandler::instance->GetModule<EntitySystem>();
	collider = entSys->GetEntity(transform->ID)->GetComponent<RectCollider>();
	collider->AddListener(std::bind(&SeekerScript::OnCollisionEnter, this), nullptr);
	rb = entSys->GetEntity(transform->ID)->GetComponent<Rigidbody>();
	rb->friction = 0.4f;
}

void SeekerScript::Update()
{
	Vectors::Vector2 dir = Vectors::Vector2(player->position.x - transform->position.x, player->position.y - transform->position.y);
	float angle = (atan2(dir.y, dir.x) * 180.0f / PI) + 90.0f;
	transform->rotation = angle;
	rb->AddForce(transform->Up() * speed * clock->GetDeltaTime());
}

void SeekerScript::SetPlayer(Transform* playerTransform)
{
	player = playerTransform;
}

void SeekerScript::OnCollisionEnter()
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

	if (health <= 0)
	{
		if (entSys->GetEntity(player->ID)->GetComponent<PlayerShooting>()->fireRate > 0.35f)
		{
			entSys->GetEntity(player->ID)->GetComponent<PlayerShooting>()->fireRate -= 0.1f;
		}
		entSys->DestroyEntity(transform->ID);
	}
}