#pragma once

#include "game.hpp"
#include "GameObject.h"

/**
* Klasa TextureManager tworzy tekstury dla grafik
*/
class TextureManager
{

public:
	/**
	* Metoda LoadTexture() zwraca teksture, pobrana z grafiki
	* @param fileName Nazwa pliku z grafika do zaladowania
	*/
	static SDL_Texture* LoadTexture(const char* fileName);
	/**
	* Metoda Draw() tworzy renderer tekstury
	* @param tex Tekstura
	* @param src Struktura reprezentujaca prostokat zrodlowy tekstury
	* @param dest Struktura reprezentujaca prostokat wyswietlany na ekranie tekstury
	*/
	static void Draw(SDL_Texture *tex, SDL_Rect src, SDL_Rect dest);

};