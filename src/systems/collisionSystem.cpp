#include <systems/collisionSystem.h>
#include <Math/collisionDetection.h>
#include <iostream>

void CollisionSystem::CheckCollisions()
{
	for (int i = 0; i < colliders.size(); i++)
	{
		for (int j = 0; j < colliders.size(); j++)
		{
			if (i == j)
			{
				continue;
			}
			if (isColliding(colliders[i]->GetRect(), colliders[j]->GetRect()))
			{
				colliders[i]->OnCollisionEnter(colliders[j]->transform);
			}
			else
			{
				colliders[i]->OnCollisionExit(colliders[j]->transform);
			}
		}
	}
}

bool CollisionSystem::isColliding(SDL_Rect first, SDL_Rect second)
{
	return Physics::OverlapRects(first, second);
}

void CollisionSystem::AddCollider(RectCollider* collider)
{
	colliders.push_back(collider);
}