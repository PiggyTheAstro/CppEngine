#include <core/game.h>
#include <components/rectRenderer.h>
#include <iostream>

Game::Game()
{
	window = SDL_CreateWindow("Shmup", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 550, 750, SDL_WINDOW_SHOWN);
	eventHandler = SDL_Event();
	serviceManager = new ServiceHandler();
	inputManager = serviceManager->AddModule<InputHandler>();
	entityManager = serviceManager->AddModule<EntitySystem>();
	renderManager = serviceManager->AddModule<RenderSystem>();
	clock = serviceManager->AddModule<Clock>();
}

void Game::Update()
{
	clock->Tick();
	inputManager->CheckEvent();
	entityManager->UpdateEntities();
	renderManager->Render();
}