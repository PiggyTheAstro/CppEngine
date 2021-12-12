#pragma once
#include <core/subsystem.h>
#include <core/entity.h>
#include <core/serviceHandler.h>
class EntitySystem : public SubSystem
{
public:
	Entity* CreateEntity();
	void UpdateEntities();
	void DestroyEntity();
private:
	std::vector<Entity*> entityList;
};