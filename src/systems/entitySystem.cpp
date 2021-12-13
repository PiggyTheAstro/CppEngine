#include <systems/entitySystem.h>
#include <iostream>
#include <algorithm>
#include <ranges>
Entity* EntitySystem::CreateEntity()
{
	Entity* ent = new Entity;
	entityList.push_back(ent);
	ent->Start(nextID);
	nextID += 1; // ID for the next entity spawned starts at 1 and increments by 1 each time
	return ent;
}

Entity* EntitySystem::GetEntity(unsigned int ID)
{
	// Lower bound returns the entity with the ID passed in or an entity above that. The lambda is necessary to compare an entity with an ID
	auto it = std::lower_bound(entityList.begin(), entityList.end(), ID, [](Entity* ent, unsigned int id) { return ent->transform.ID < id; });
	if (it != entityList.cend() && (*it)->transform.ID == ID) // Return entity if the index is not out of bounds and the IDs match
	{
		return *it;
	}
	return nullptr;
}

void EntitySystem::UpdateEntities()
{
	for (int i = 0; i < entityList.size(); i++)
	{
		entityList[i]->Update();
	}
}

void EntitySystem::DestroyEntity() // TODO: This
{

}
