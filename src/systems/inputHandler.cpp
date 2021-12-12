#include <systems/inputHandler.h>
#include <SDL.h>
#include <iostream>

void InputHandler::CheckEvent()
{
	SDL_Event eventHandler = SDL_Event();
	while (SDL_PollEvent(&eventHandler))
	{
		switch (eventHandler.type)
		{
		case SDL_QUIT:
			SDL_Quit();
			break;

		case SDL_KEYDOWN:
			PushEvent(eventHandler.key.keysym.sym);
			break;

		case SDL_KEYUP:
			PopEvent(eventHandler.key.keysym.sym);
			break;
		}
	}
}

void InputHandler::PushEvent(int eventValue)
{
	for (int i = 0; i < keys.size(); i++)
	{
		if (keys[i] == eventValue)
		{
			return;
		}
	}
	keys.push_back(eventValue);
}

void InputHandler::PopEvent(int eventValue)
{
	for (int i = 0; i < keys.size(); i++)
	{
		if (keys[i] == eventValue)
		{
			keys.erase(keys.begin() + i);
			return;
		}
	}
}

bool InputHandler::GetKey(int key)
{
	for (int i = 0; i < keys.size(); i++)
	{
		if (keys[i] == key)
		{
			return true;
		}
	}
	return false;
}