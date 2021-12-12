#pragma once
#include <vector>
#include <Math/vectors.h>
#include <core/component.h>
#include <core/transform.h>

class Entity 
{
public:
	Transform transform;

	void Start();
	void Update();

	template <typename Comp>
	void AddComponent()
	{
		Comp* comp = new Comp();
		if (dynamic_cast<Component*>(comp) != nullptr) 
		{
			components.push_back(comp);
			comp->Start(&transform);
		}
		else
		{
			delete comp;
		}
	}

	template <typename Comp>
	Comp* GetComponent()
	{
		for (int i = 0; i < components.size(); i++)
		{
			Comp* component = dynamic_cast<Comp*>(components[i]);
			if (component != nullptr)
			{
				return component;
			}
		}
		return nullptr;
	}

	template <typename Comp>
	void RemoveComponent()
	{
		for (int i = 0; i < components.size(); i++) 
		{
			if (dynamic_cast<Comp*>(components[i]) != nullptr)
			{
				components.erase(components.begin() + i);
			}
		}
	}

private:
	std::vector<Component*> components;
};