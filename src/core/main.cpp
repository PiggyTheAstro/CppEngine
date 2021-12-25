#include <SDL.h>
#include <core/game.h>
#include <components/rectRenderer.h>
#include <components/game/playerMovement.h>
#include <systems/assetManager.h>
#include <components/spriteRenderer.h>
#include <components/game/playerShooting.h>
#include <components/rectCollider.h>
#include <components/game/asteroidSpawner.h>
using namespace Vectors;

int main(int argc, char** argv)
{
	Game game = Game();
	EntitySystem* entitySystem = ServiceHandler::instance->GetModule<EntitySystem>();
	SDL_DisplayMode display;
	SDL_GetCurrentDisplayMode(0, &display);
	Entity* player = entitySystem->CreateEntity();
	player->AddComponent<SpriteRenderer>();
	player->GetComponent<SpriteRenderer>()->SetSprite("resources/ship.bmp");
	player->AddComponent<Rigidbody>();
	player->AddComponent<RectCollider>();
	player->AddComponent<PlayerMovement>();
	player->AddComponent<PlayerShooting>();
	player->transform.position = Vector2(display.w / 2, display.h / 2);
	player->transform.scale = Vector2(32.0f, 32.0f);
	Entity* playerT = ServiceHandler::instance->GetModule<EntitySystem>()->CreateEntity();
	playerT->AddComponent<AsteroidSpawner>();
	playerT->transform.position = Vector2(200.0f, 300.0f);
	playerT->transform.scale = Vector2(20.0f, 20.0f);
	while (ServiceHandler::instance->isRunning)
	{
		game.Update();
	}
	game.Cleanup();
	SDL_Quit();
	return 0;
}