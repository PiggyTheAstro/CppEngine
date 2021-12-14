#include <systems/renderSystem.h>
#include <SDL.h>
#include <core/serviceHandler.h>
RenderSystem::RenderSystem()
{
	renderables = std::vector<SDL_Rect*>();
	sprites = std::vector<Sprite*>();
	renderer = SDL_CreateRenderer(SDL_GetWindowFromID(1), 0, SDL_RENDERER_PRESENTVSYNC); // SDL Window IDs start at 1
}

void RenderSystem::Render() // Add sprite rendering support
{
	SDL_SetRenderDrawColor(renderer, 0, 0, 0, SDL_ALPHA_OPAQUE);
	SDL_RenderClear(renderer);
	SDL_SetRenderDrawColor(renderer, 255, 255, 255, SDL_ALPHA_OPAQUE);
	RenderRects();
	RenderSprites();
	SDL_RenderPresent(renderer);
}

void RenderSystem::AddRenderable(SDL_Rect* rect)
{
	renderables.push_back(rect);
}

void RenderSystem::AddRenderable(Sprite* sprite)
{
	sprites.push_back(sprite);
}

void RenderSystem::RenderRects()
{
	for (int i = 0; i < renderables.size(); i++)
	{
		SDL_RenderFillRect(renderer, renderables[i]);
	}
}

void RenderSystem::RenderSprites()
{
	for (int i = 0; i < sprites.size(); i++)
	{
		SDL_RenderCopy(renderer, sprites[i]->texture, 0, &sprites[i]->rect);
	}
}