#pragma once
#include <core/component.h>
#include <systems/clock.h>
#include <systems/entitySystem.h>

class AsteroidSpawner : public Component
{
public:
	void Start(Transform* parent) override;
	void Update() override;

private:
	Transform* transform = nullptr;
	EntitySystem* entSys = nullptr;
	Transform* player = nullptr;
	Clock* clock = nullptr;
	void Spawn();
	void CreateAsteroid();
	float difficulty = 0.0f;
};