#pragma once
#include <core/subsystem.h>
#include <SDL.h>
#include <components/rectCollider.h>
#include <vector>

class CollisionSystem : public SubSystem
{
public:
	void CheckCollisions();
	bool isColliding(SDL_Rect first, SDL_Rect second);
	void AddCollider(RectCollider* collider);
private:
	std::vector<RectCollider*> colliders;
};