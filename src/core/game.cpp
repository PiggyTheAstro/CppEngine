#include <core/game.h>
#include <components/rectRenderer.h>
#include <iostream>

Game::Game()
{
	window = SDL_CreateWindow("Shmup", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 550, 750, SDL_WINDOW_SHOWN); // TODO: Make game fullscreen?
	eventHandler = SDL_Event();
	serviceManager = new ServiceHandler();
	inputManager = serviceManager->AddModule<InputHandler>();
	entityManager = serviceManager->AddModule<EntitySystem>();
	renderManager = serviceManager->AddModule<RenderSystem>();
	clock = serviceManager->AddModule<Clock>();
}

void Game::Update() // All these functions could be turned into an update interface for each subsystem
{
	clock->Tick();
	inputManager->CheckEvent();
	entityManager->UpdateEntities();
	renderManager->Render();
}