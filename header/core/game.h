#pragma once
#include <vector>
#include <SDL.h>
#include <systems/inputHandler.h>
#include <systems/entitySystem.h>
#include <systems/renderSystem.h>
#include <systems/clock.h>
#include <core/serviceHandler.h>

class Game
{
public:
	Game();
	void Update();
	ServiceHandler* serviceManager;

private:
	std::vector<SubSystem*> systems;
	SDL_Window* window;
	SDL_Event eventHandler;
	InputHandler* inputManager;
	EntitySystem* entityManager;
	RenderSystem* renderManager;
	Clock* clock;
};