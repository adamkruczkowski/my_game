#include "swamp.h"
#include "TextureManager.hpp"

Swamp::Swamp(const char* texturesheet, int x, int y) :
	GameObject::GameObject(texturesheet, x, y)
{
	srcRect.x = 0;
	srcRect.y = 0;
	srcRect.w = 128;
	srcRect.h = 128;

	destRect.w = srcRect.w;
	destRect.h = srcRect.h;
}

void Swamp::Update()
{

	destRect.x = xpos;
	destRect.y = ypos;

}
