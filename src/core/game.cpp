#include <core/game.h>
#include <components/rectRenderer.h>

Game::Game()
{
	window = SDL_CreateWindow("Shmup", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 550, 750, SDL_WINDOW_MAXIMIZED); // TODO: Make game fullscreen?
	serviceManager = new ServiceHandler();
	subSystems.push_back(serviceManager->AddModule<InputHandler>());
	subSystems.push_back(serviceManager->AddModule<EntitySystem>());
	subSystems.push_back(serviceManager->AddModule<Camera>());
	subSystems.push_back(serviceManager->AddModule<RenderSystem>());
	subSystems.push_back(serviceManager->AddModule<Clock>());
	subSystems.push_back(serviceManager->AddModule<AssetManager>());
	subSystems.push_back(serviceManager->AddModule<CollisionSystem>());
}

void Game::Update()
{
	for (int i = 0; i < subSystems.size(); i++)
	{
		subSystems[i]->Update();
	}
}

void Game::Cleanup()
{
	for (int i = 0; i < subSystems.size(); i++)
	{
		delete subSystems[i];
	}
}