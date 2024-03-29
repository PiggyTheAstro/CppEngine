#pragma once
#include <SDL.h>
#include <systems/inputHandler.h>
#include <systems/entitySystem.h>
#include <systems/renderSystem.h>
#include <systems/clock.h>
#include <systems/assetManager.h>
#include <systems/collisionSystem.h>
#include <systems/camera.h>
#include <core/serviceHandler.h>

class Game
{
public:
	Game();
	void Update();
	void Cleanup();
	ServiceHandler* serviceManager;

private:
	std::vector<SubSystem*> subSystems;
	SDL_Window* window;
};