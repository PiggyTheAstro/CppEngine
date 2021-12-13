#pragma once
#include <core/subsystem.h>
#include <SDL.h>

class RenderSystem : public SubSystem // TODO: Add sprite rendering support
{
public:
	RenderSystem();
	RenderSystem(SDL_Renderer* mainRenderer);
	void Render();
	void AddRenderable(SDL_FRect* rect);
private:
	SDL_Renderer* renderer;
	std::vector<SDL_FRect*> renderables;

};