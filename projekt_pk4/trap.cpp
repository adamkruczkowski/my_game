#include "trap.h"
#include "TextureManager.hpp"

Trap::Trap(const char* texturesheet, int x, int y):
	GameObject::GameObject(texturesheet, x, y)
	{
	srcRect.x = 0;
	srcRect.y = 0;
	srcRect.w = 32;
	srcRect.h = 32;

	destRect.w = srcRect.w;
	destRect.h = srcRect.h;
	}

void Trap::Update()
{

	destRect.x = xpos;
	destRect.y = ypos;

}
