#pragma once
#include <Math/vectors.h>
#include <SDL.h>

namespace Physics
{
	bool OverlapRects(SDL_Rect first, SDL_Rect second);
	bool OverlapSphere(Vectors::Vector2 firstCenter, Vectors::Vector2 secondCenter, float firstRadius, float secondRadius);
}