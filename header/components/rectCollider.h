#pragma once
#include <core/component.h>
#include <vector>
#include <SDL.h>
#include <functional>

class RectCollider : public Component
{
public:
	Transform* transform;
	void Start(Transform* parent) override;
	void Update() override;
	void AddListener(std::function<void()> enterFunc, std::function<void()> exitFunc);
	void OnCollisionEnter(Transform* other);
	void OnCollisionExit(Transform* other);
	SDL_Rect GetRect();

private:
	SDL_Rect rect;
	std::vector<std::function<void()>> enterListeners;
	std::vector<std::function<void()>> exitListeners;
	std::vector<int> collided;
};