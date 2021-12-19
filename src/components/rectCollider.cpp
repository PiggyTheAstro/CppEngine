#include <components/rectCollider.h>
#include <core/serviceHandler.h>
#include <iostream>
#include <systems/collisionSystem.h>

void RectCollider::Start(Transform* parent)
{
	transform = parent;
	rect = SDL_Rect();
	ServiceHandler::instance->GetModule<CollisionSystem>()->AddCollider(this);
}

void RectCollider::Update()
{
	rect.x = transform->position.x;
	rect.y = transform->position.y;
	rect.w = transform->scale.x;
	rect.h = transform->scale.y;
}

void RectCollider::AddListener(Component* comp)
{

}

void RectCollider::OnCollisionEnter(Transform* other)
{
	for (int id : collided)
	{
		if (other->ID == id)
		{
			return;
		}
	}
	std::cout << "h" << std::endl;
	collided.push_back(other->ID);
}

void RectCollider::OnCollisionExit(Transform* other)
{
	for (int i = collided.size() - 1; i > -1; i--)
	{
		if (other->ID == collided[i])
		{
			std::cout << "o" << std::endl;
			collided.erase(collided.begin() + i);
		}
	}
}

SDL_Rect RectCollider::GetRect()
{
	return rect;
}