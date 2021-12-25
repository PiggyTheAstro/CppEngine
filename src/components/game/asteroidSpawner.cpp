#include <components/game/asteroidSpawner.h>
#include <Math/random.h>
#include <core/serviceHandler.h>
#include <systems/entitySystem.h>
#include <components/spriteRenderer.h>
#include <components/game/asteroidScript.h>
#include <components/rectCollider.h>

void AsteroidSpawner::Start(Transform* parent)
{
	transform = parent;
	entSys = ServiceHandler::instance->GetModule<EntitySystem>();
	player = &(entSys->GetEntity(1)->transform); // The player's ID will always be 1.
	clock = ServiceHandler::instance->GetModule<Clock>();
	clock->StartTimer(std::bind(&AsteroidSpawner::Spawn, this), Random::Rand(0.5f, 3.0f));
}

void AsteroidSpawner::Update()
{
	
}

void AsteroidSpawner::Spawn()
{
	int xDir = Random::Randint(0, 1) % 2 * 2 - 1; // Generates either -1 or 1
	int yDir = Random::Randint(0, 1) % 2 * 2 - 1;
	transform->position.x = player->position.x + (Random::Randint(1000, 1500) * xDir);
	transform->position.y = player->position.y + (Random::Randint(1000, 1500) * yDir);
	CreateAsteroid();
	clock->StartTimer(std::bind(&AsteroidSpawner::Spawn, this), Random::Rand(0.5f, 1.5f));
}

void AsteroidSpawner::CreateAsteroid()
{
	Entity* asteroid = entSys->CreateEntity();
	asteroid->transform.position = transform->position;
	asteroid->AddComponent<SpriteRenderer>();
	asteroid->GetComponent<SpriteRenderer>()->SetSprite("resources/asteroid.bmp");
	asteroid->AddComponent<RectCollider>();
	asteroid->AddComponent<AsteroidScript>();
	asteroid->GetComponent<AsteroidScript>()->SetPlayer(player);
}