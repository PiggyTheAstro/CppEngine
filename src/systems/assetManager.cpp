#include <systems/assetManager.h>
#include <iostream>
SDL_Texture* AssetManager::LoadTexture(std::string path)
{
	for (int i = 0; i < tempTextures.size(); i++)
	{
		if (tempTextures[i]->path == path) 
		{
			tempTextures[i]->refCount += 1;
			return tempTextures[i]->texture;
		}
	}
	SDL_Surface* img = SDL_LoadBMP(path.c_str());
	SDL_Texture* tex = SDL_CreateTextureFromSurface(SDL_GetRenderer(SDL_GetWindowFromID(1)), img);
	SDL_FreeSurface(img);
	tempTextures.push_back(new Renderable(tex, path));
	std::cout << tex << std::endl;
	return tex;
}

SDL_Texture* AssetManager::LoadTexturePermanent(std::string path)
{
	return nullptr;
}

void AssetManager::Dereference(SDL_Texture* texture)
{
	for (int i = 0; i < tempTextures.size(); i++)
	{
		if (texture == tempTextures[i]->texture)
		{
			tempTextures[i]->refCount -= 1;
			if (tempTextures[i]->refCount <= 0)
			{
				SDL_DestroyTexture(tempTextures[i]->texture);
				delete tempTextures[i];
				tempTextures.erase(tempTextures.begin() + i);
			}
		}
	}
}