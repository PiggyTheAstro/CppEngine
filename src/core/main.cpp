#include <SDL.h>
#include <core/game.h>
#include <components/rectRenderer.h>
#include <components/playerMovement.h>
#include <iostream>
int main(int argc, char** argv)
{
	Game game = Game();
	Clock* clock = ServiceHandler::instance->GetModule<Clock>();
	Entity* player = ServiceHandler::instance->GetModule<EntitySystem>()->CreateEntity();
	player->AddComponent<RectRenderer>();
	player->AddComponent<PlayerMovement>();
	player->transform.position = Vectors::Vector2(400.0f, 300.0f);
	player->transform.scale = Vectors::Vector2(20.0f, 20.0f);
	while (true)
	{
		game.Update();
	}
	return 0;
}