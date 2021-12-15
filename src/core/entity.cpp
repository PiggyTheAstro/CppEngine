#include <core/entity.h>
#include <iostream>
Entity::~Entity()
{
	for (int i = components.size() - 1; i > -1; i--) // Deletes and frees memory for all components
	{
		Component* component = components[i];
		components.erase(components.begin() + i);
		std::cout << component << std::endl;
		delete component;
	}
}
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