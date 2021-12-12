#include <components/rectRenderer.h>
#include <iostream>
#include <core/serviceHandler.h>

RectRenderer::RectRenderer()
{
	transform = nullptr;
	rect = SDL_FRect();
	renderModule = nullptr;
}

void RectRenderer::Start(Transform* parent)
{
	transform = parent;
	rect = SDL_FRect();
	renderModule = ServiceHandler::instance->GetModule<RenderSystem>();
	renderModule->AddRenderable(&(this->rect));
}

void RectRenderer::Update()
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