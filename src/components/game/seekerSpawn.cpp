#include <components/game/seekerSpawn.h>
#include <Math/random.h>
#include <core/serviceHandler.h>
#include <systems/entitySystem.h>
#include <components/spriteRenderer.h>
#include <components/rectCollider.h>
#include <components/rigidbody.h>
#include <components/game/seekerScript.h>

void SeekerSpawner::Start(Transform* parent)
{
	transform = parent;
	entSys = ServiceHandler::instance->GetModule<EntitySystem>();
	player = &(entSys->GetEntity(1)->transform); // The player's ID will always be 1.
	clock = ServiceHandler::instance->GetModule<Clock>();
	clock->StartTimer(std::bind(&SeekerSpawner::Spawn, this), Random::Rand(0.3f, 1.0f));
}

void SeekerSpawner::Update()
{

}

void SeekerSpawner::Spawn()
{
	int xDir = Random::Randint(0, 1) % 2 * 2 - 1; // Generates either -1 or 1
	int yDir = Random::Randint(0, 1) % 2 * 2 - 1;
	transform->position.x = player->position.x + (Random::Randint(1000, 1300) * xDir);
	transform->position.y = player->position.y + (Random::Randint(1000, 1300) * yDir);
	CreateSeeker();
	clock->StartTimer(std::bind(&SeekerSpawner::Spawn, this), Random::Rand(15.0f, 30.0f) - difficulty);
}

void SeekerSpawner::CreateSeeker()
{
	Entity* seeker = entSys->CreateEntity();
	seeker->transform.position = transform->position;
	seeker->AddComponent<RectCollider>();
	seeker->AddComponent<SpriteRenderer>();
	seeker->GetComponent<SpriteRenderer>()->SetSprite("resources/enemyship.bmp");
	seeker->AddComponent<Rigidbody>();
	seeker->AddComponent<SeekerScript>();
	seeker->GetComponent<SeekerScript>()->SetPlayer(player);
	seeker->GetComponent<SeekerScript>()->health += (difficulty * 2.0f);
	seeker->GetComponent<SeekerScript>()->speed += (difficulty * 2.0f);
	if (difficulty < 15.5f)
	{
		difficulty += Random::Rand(0.1f, 0.3f);
	}
}