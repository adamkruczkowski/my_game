#include "text.h"

Text::Text(SDL_Renderer* ren, const char* write, TTF_Font* font, int xp, int yp):
	GameObject::GameObject()
	{
		SDL_Color color = { 0,0,0 };
		SDL_Surface* textSurface = TTF_RenderText_Solid(font, write, color);
		xpos = xp;
		ypos = yp;
		writeText = (char*) write;
		objTexture = SDL_CreateTextureFromSurface(ren, textSurface);
		SDL_FreeSurface(textSurface);

		srcRect.w = 150;
		srcRect.h = 150;
		destRect.x = 0;
		destRect.y = 0;

		destRect.w = 150;
		destRect.h = 100;
		destRect.x = xp;
		destRect.y = yp;
	}

void Text::Update(TTF_Font *font, SDL_Renderer * ren)
{
	SDL_Color color = { 255,0,0 };
	const char* textu = writeText;
	SDL_Surface* textSurface = TTF_RenderText_Solid(font, textu, color);

	objTexture = SDL_CreateTextureFromSurface(ren, textSurface);
	SDL_FreeSurface(textSurface);

	destRect.x = xpos;
	destRect.y = ypos;
}
