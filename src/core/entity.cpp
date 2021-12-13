#include <core/entity.h>

void Entity::Start(unsigned int identifier)
{
	ID = identifier;
	transform = Transform(ID);
	for (int i = 0; i < components.size(); i++)
	{
		components[i]->Start(&transform);
	}
}

void Entity::Update()
{
	for (int i = 0; i < components.size(); i++)
	{
		components[i]->Update();
	}
}