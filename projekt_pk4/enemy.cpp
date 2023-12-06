#include "enemy.h"
#include "TextureManager.hpp"


Enemy::Enemy(const char* texturesheet, int x, int y):
	GameObject::GameObject(texturesheet, x, y)
	{
		srcRect.x = 0;
		srcRect.y = 0;
		srcRect.w = 32;
		srcRect.h = 32;

		destRect.w = srcRect.w * 2;
		destRect.h = srcRect.h * 2;
		destRect.x = xpos;
		destRect.y = ypos;
	}

void Enemy::Update(SDL_Rect playerR)
{

	if (isChasing)
	{
		int xx, yy;
		int dx = playerR.x - destRect.x;
		int dy = playerR.y - destRect.y;

		double length = sqrt(dx * dx + dy * dy);

		if (length > 0) 
		{
			xx = (int) ((dx*2)  / length);
			yy = (int)((dy*2)/ length);
		}

		if (dx > 2)
			xx / 2;
		if (dy > 2)
			yy / 2;
		destRect.x += xx ;
		destRect.y += yy ;
	}

}


