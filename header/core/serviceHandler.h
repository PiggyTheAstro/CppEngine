#pragma once
#include <vector>
#include <core/subsystem.h>

class ServiceHandler
{
public:
	static ServiceHandler* instance;

	ServiceHandler();

	template <typename System>
	System* GetModule()
	{
		for (int i = 0; i < systems.size(); i++)
		{
			System* subsystem = dynamic_cast<System*>(systems[i]);
			if (subsystem != nullptr)
			{
				return subsystem;
			}
		}
		return nullptr;
	}

	template <typename System>
	System* AddModule()
	{
		System* sys = new System();
		if (dynamic_cast<SubSystem*>(sys) != nullptr)
		{
			systems.push_back(sys);
			return sys;
		}
		delete sys;
		return nullptr;
	}

private:
	std::vector<SubSystem*> systems;
};