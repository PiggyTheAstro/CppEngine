#pragma once
#include <SDL.h>

class Sprite
{
public:
	SDL_Rect rect;
	SDL_Texture* texture;
	float rotation;
};