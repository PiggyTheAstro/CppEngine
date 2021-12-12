#pragma once
#include <core/component.h>
#include <SDL.h>
#include <systems/renderSystem.h>

class RectRenderer : public Component
{
public:
	RectRenderer();
	void Start(Transform* parent) override;
	void Update() override;
	SDL_FRect* Rect();

private:
	Transform* transform;
	SDL_FRect rect;
	RenderSystem* renderModule;
};