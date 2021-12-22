#pragma once
#include <core/component.h>
#include <systems/clock.h>

class AsteroidSpawner : public Component
{
public:
	void Start(Transform* parent) override;
	void Update() override;

private:
	Transform* transform = nullptr;
	Clock* clock = nullptr;
	void Spawn();
};