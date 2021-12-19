#pragma once
#include <core/component.h>
#include <vector>
#include <SDL.h>

class RectCollider : public Component
{
public:
	Transform* transform;
	void Start(Transform* parent) override;
	void Update() override;
	void AddListener(Component* comp);
	void OnCollisionEnter(Transform* other);
	void OnCollisionExit(Transform* other);
	SDL_Rect GetRect();

private:
	SDL_Rect rect;
	std::vector<Component*> listeners;
	std::vector<int> collided;
};