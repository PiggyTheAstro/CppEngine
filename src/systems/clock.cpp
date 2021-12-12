#include <systems/clock.h>

Clock::Clock()
{
	lastTime = 0;
	deltaTime = 0;
}

void Clock::Tick()
{
	unsigned int currentTime = SDL_GetTicks();
	deltaTime = currentTime - lastTime;
	lastTime = currentTime;
}

float Clock::GetDeltaTime()
{
	return deltaTime / 1000.0f;
}