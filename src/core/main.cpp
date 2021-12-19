#include <SDL.h>
#include <core/game.h>
#include <components/rectRenderer.h>
#include <components/game/playerMovement.h>
#include <systems/assetManager.h>
#include <components/spriteRenderer.h>
#include <components/game/playerShooting.h>
#include <components/rectCollider.h>
using namespace Vectors;

int main(int argc, char** argv)
{
	Game game = Game();
	EntitySystem* entitySystem = ServiceHandler::instance->GetModule<EntitySystem>();
	Entity* player = entitySystem->CreateEntity();
	player->AddComponent<SpriteRenderer>();
	player->GetComponent<SpriteRenderer>()->SetSprite("resources/ship.bmp");
	player->AddComponent<Rigidbody>();
	player->AddComponent<PlayerMovement>();
	player->AddComponent<PlayerShooting>();
	player->AddComponent<RectCollider>();
	player->transform.position = Vector2(400.0f, 300.0f);
	player->transform.scale = Vector2(32.0f, 32.0f);
	Entity* playerT = entitySystem->CreateEntity();
	playerT->AddComponent<RectRenderer>();
	playerT->AddComponent<Rigidbody>();
	playerT->AddComponent<RectCollider>();
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