#include "health.h"
#include "TextureManager.hpp"

Health::Health(const char* texturesheet, int x, int y):
	GameObject::GameObject(texturesheet, x, y)
	{

		xpos = x;
		ypos = y;
		srcRect.x = 0;
		srcRect.y = 0;
		srcRect.w = 32;
		srcRect.h = 32;

		destRect.x = xpos;
		destRect.y = ypos;
		destRect.w = srcRect.w;
		destRect.h = srcRect.h;

	}
