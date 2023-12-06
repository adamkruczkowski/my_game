#include "winscreen.h"
#include "TextureManager.hpp"

Winscreen::Winscreen(const char* texturesheet, int x, int y) :
	GameObject::GameObject(texturesheet, x, y)
{
	srcRect.x = 0;
	srcRect.y = 0;
	srcRect.w = 800;
	srcRect.h = 640;

	destRect.w = srcRect.w;
	destRect.h = srcRect.h;
}