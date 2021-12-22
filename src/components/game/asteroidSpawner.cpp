#include <components/game/asteroidSpawner.h>
#include <Math/random.h>
#include <core/serviceHandler.h>
#include <iostream>

void AsteroidSpawner::Start(Transform* parent)
{
	transform = parent;
	clock = ServiceHandler::instance->GetModule<Clock>();
	clock->StartTimer(std::bind(&AsteroidSpawner::Spawn, this), Random::Rand(0.5f, 3.0f));
}

void AsteroidSpawner::Update()
{
	
}

void AsteroidSpawner::Spawn()
{
	clock->StartTimer(std::bind(&AsteroidSpawner::Spawn, this), Random::Rand(0.5f, 3.0f));
}