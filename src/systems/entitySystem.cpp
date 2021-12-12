#include <systems/entitySystem.h>
#include <iostream>

Entity* EntitySystem::CreateEntity()
{
	Entity* ent = new Entity;
	entityList.push_back(ent);
	ent->Start();
	return ent;
}

void EntitySystem::UpdateEntities()
{
	for (int i = 0; i < entityList.size(); i++)
	{
		entityList[i]->Update();
	}
}

void EntitySystem::DestroyEntity()
{

}
