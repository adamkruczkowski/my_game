#include "GameObject.h"
#include "TextureManager.hpp"

GameObject::GameObject(const char* texturesheet, int x, int y)
{

	objTexture = TextureManager::LoadTexture(texturesheet);

	xpos = x;
	ypos = y;

}

GameObject::GameObject()
{

}

GameObject::~GameObject()
{

}

void GameObject::Update()
{

}

void GameObject::Render()
{
	SDL_RenderCopy(Game::renderer, objTexture, &srcRect, &destRect);
}

bool GameObject::isCollide(SDL_Rect destRectt, int size1, int size2)
{

	if (destRectt.x + size1 >= destRect.x && destRectt.y >= destRect.y - size1 && destRectt.y <= destRect.y + size2 && destRectt.x <= destRect.x + size2)
	{
		return true;
	}
	else
	{
		return false;
	}

}

