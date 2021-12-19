#pragma once
#include <SDL.h>
#include <core/subsystem.h>

class Clock : public SubSystem
{
public:
	Clock();
	void Tick();
	float GetDeltaTime();

private:
	unsigned int deltaTime;
	unsigned int lastTime;
};