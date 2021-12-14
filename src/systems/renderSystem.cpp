#include <systems/renderSystem.h>
#include <SDL.h>
#include <core/serviceHandler.h>
#include <systems/assetManager.h>
RenderSystem::RenderSystem()
{
	renderables = std::vector<SDL_FRect*>();
	renderer = SDL_CreateRenderer(SDL_GetWindowFromID(1), 0, SDL_RENDERER_PRESENTVSYNC); // SDL Window IDs start at 1
}

RenderSystem::RenderSystem(SDL_Renderer* mainRenderer)
{
	renderables = std::vector<SDL_FRect*>();
	renderer = mainRenderer;
}

void RenderSystem::Render() // Add sprite rendering support
{
	SDL_Texture* texture = ServiceHandler::instance->GetModule<AssetManager>()->LoadTexture("resources/ship.bmp");
	SDL_SetRenderDrawColor(renderer, 0, 0, 0, SDL_ALPHA_OPAQUE);
	SDL_RenderClear(renderer);
	SDL_SetRenderDrawColor(renderer, 255, 255, 255, SDL_ALPHA_OPAQUE);
	for (int i = 0; i < renderables.size(); i++)
	{
		SDL_Rect intRect = SDL_Rect();
		intRect.x = renderables[i]->x;
		intRect.y = renderables[i]->y;
		intRect.w = renderables[i]->w;
		intRect.h = renderables[i]->h;
		SDL_RenderCopy(renderer, texture, 0, &intRect);
		//SDL_RenderFillRectF(renderer, renderables[i]);
	}
	SDL_RenderPresent(renderer);
}

void RenderSystem::AddRenderable(SDL_FRect* rect)
{
	renderables.push_back(rect);
}