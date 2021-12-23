#include <components/game/asteroidSpawner.h>
#include <Math/random.h>
#include <core/serviceHandler.h>
#include <systems/entitySystem.h>
#include <iostream>

void AsteroidSpawner::Start(Transform* parent)
{
	transform = parent;
	player = &(ServiceHandler::instance->GetModule<EntitySystem>()->GetEntity(1)->transform); // The player's ID will always be 1.
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
	transform->position.x = player->position.x + (Random::Randint(1000, 2000) * xDir);
	transform->position.y = player->position.y + (Random::Randint(1000, 2000) * yDir);
	clock->StartTimer(std::bind(&AsteroidSpawner::Spawn, this), Random::Rand(0.5f, 3.0f));
}