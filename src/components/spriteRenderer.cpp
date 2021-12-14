#include <components/spriteRenderer.h>
#include <core/serviceHandler.h>
#include <systems/assetManager.h>
void SpriteRenderer::Start(Transform* parent)
{
	transform = parent;
	renderModule = ServiceHandler::instance->GetModule<RenderSystem>();
	assetModule = ServiceHandler::instance->GetModule<AssetManager>();
	sprite = new Sprite();
	sprite->texture = assetModule->LoadTexture("resources/ship.bmp"); // Hardcoded, to be replaced soon
	sprite->rect = SDL_Rect();
	renderModule->AddRenderable(sprite);
}

void SpriteRenderer::Update()
{
	sprite->rect.x = transform->position.x;
	sprite->rect.y = transform->position.y;
	sprite->rect.w = transform->scale.x;
	sprite->rect.h = transform->scale.y;
}