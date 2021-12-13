#pragma once
#include <core/subsystem.h>
#include <core/entity.h>
#include <core/serviceHandler.h>
class EntitySystem : public SubSystem
{
public:
	Entity* CreateEntity();
	Entity* GetEntity(unsigned int ID);
	void UpdateEntities();
	void DestroyEntity();
private:
	std::vector<Entity*> entityList;
	unsigned int nextID = 1;
};