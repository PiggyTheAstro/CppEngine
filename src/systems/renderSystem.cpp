#include <systems/renderSystem.h>
#include <SDL.h>
#include <core/serviceHandler.h>
RenderSystem::RenderSystem()
{
	rects = std::vector<SDL_Rect*>();
	sprites = std::vector<Sprite*>();
	renderer = SDL_CreateRenderer(SDL_GetWindowFromID(1), 0, SDL_RENDERER_PRESENTVSYNC); // SDL Window IDs start at 1
}

void RenderSystem::Render()
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
	rects.push_back(rect);
}

void RenderSystem::AddRenderable(Sprite* sprite)
{
	sprites.push_back(sprite);
}

void RenderSystem::RemoveRenderable(Sprite* sprite)
{
	for (int i = 0; i < sprites.size(); i++)
	{
		if (sprites[i] == sprite)
		{
			sprites.erase(sprites.begin() + i);
		}
	}
}

void RenderSystem::RenderRects()
{
	for (int i = 0; i < rects.size(); i++)
	{
		SDL_RenderFillRect(renderer, rects[i]);
	}
}

void RenderSystem::RenderSprites()
{
	for (int i = 0; i < sprites.size(); i++)
	{
		SDL_RenderCopyEx(renderer, sprites[i]->texture, 0, &sprites[i]->rect, sprites[i]->rotation, 0, SDL_FLIP_NONE);
	}
}