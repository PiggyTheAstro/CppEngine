#include <components/rectRenderer.h>
#include <iostream>
#include <core/serviceHandler.h>

void RectRenderer::Start(Transform* parent)
{
	transform = parent;
	rect = SDL_FRect();
	renderModule = ServiceHandler::instance->GetModule<RenderSystem>();
	renderModule->AddRenderable(&(this->rect));
}

void RectRenderer::Update() // Updates the rect coordinates to the transform's
{
	rect.x = transform->position.x;
	rect.y = transform->position.y;
	rect.w = transform->scale.x;
	rect.h = transform->scale.y;
}

SDL_FRect* RectRenderer::Rect()
{
	return &rect;
}