#pragma once
#include <core/subsystem.h>
#include <core/sprite.h>
#include <SDL.h>

class RenderSystem : public SubSystem // TODO: Add sprite rendering support
{
public:
	RenderSystem();
	void Render();
	void AddRenderable(SDL_Rect* rect);
	void AddRenderable(Sprite* sprite);
	void RemoveRenderable(Sprite* sprite);
private:
	void RenderRects();
	void RenderSprites();
	SDL_Renderer* renderer;
	std::vector<SDL_Rect*> rects;
	std::vector<Sprite*> sprites;

};