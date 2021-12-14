#include <SDL.h>
#include <core/game.h>
#include <components/rectRenderer.h>
#include <components/playerMovement.h>
#include <iostream>
#include <systems/assetManager.h>
int main(int argc, char** argv)
{
	Game game = Game();
	Entity* player = ServiceHandler::instance->GetModule<EntitySystem>()->CreateEntity();
	player->AddComponent<RectRenderer>();
	player->AddComponent<PlayerMovement>();
	player->transform.position = Vectors::Vector2(400.0f, 300.0f);
	player->transform.scale = Vectors::Vector2(20.0f, 20.0f);
	Entity* playerT = ServiceHandler::instance->GetModule<EntitySystem>()->CreateEntity();
	playerT->AddComponent<RectRenderer>();
	playerT->AddComponent<PlayerMovement>();
	playerT->transform.position = Vectors::Vector2(200.0f, 300.0f);
	playerT->transform.scale = Vectors::Vector2(20.0f, 20.0f);
	playerT->RemoveComponent<PlayerMovement>();
	while (true)
	{
		game.Update();
	}
	return 0;
}