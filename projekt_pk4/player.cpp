#include "player.hpp"


Player::Player(const char* texturesheet, int x, int y):
	GameObject::GameObject(texturesheet, x, y)
	{

		srcRect.x = 0;
		srcRect.y = 0;
		srcRect.w = 32;
		srcRect.h = 32;

		destRect.x = x;
		destRect.y = y;
		destRect.w = srcRect.w*2;
		destRect.h = srcRect.h*2;

	}


void Player::Update()
{

	if (mR)
	{
		if (destRect.x <= 736)
		{
			destRect.x += velocity;
		}		
	}
	if (mL)
	{
		if (destRect.x >= 0)
		{
			destRect.x += -velocity;
		}
	}
	if (mU)
	{
		if (destRect.y >= 0)
		{
			destRect.y += -velocity;
		}
	}
	if (mD)
	{
		if (destRect.y <= 576)
		{
			destRect.y += velocity;
		}
	}

}
