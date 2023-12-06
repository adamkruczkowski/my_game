#pragma once

#include "GameObject.h"
#include <string>
#include <SDL_ttf.h>
/**
* Klasa Text odpowiada za wyswietlanie tekstu na ekranie, ktory informuje o stanie zdrowia gracza, czy aktualnej serii wygranych. Dziedziczy po klasie GameObject
*/
class Text : public GameObject
{
public:
	/**
	* Przechowuje teskt, ktory ma byc wyswietlony na ekranie
	*/
	char* writeText = NULL;
	/**
	* Kostruktor argumentowy
	* @param ren Renderer tesktu
	* @param textu Tekst, ktory ma zostac wypisany na ekranie
	* @param font Czcionka uzywana do wypisania tekstu
	* @param xpos Pozycja x tektu na ekranie
	* @param ypos Pozycja y teksty na ekranie
	*/
	Text(SDL_Renderer* ren, const char* textu, TTF_Font* font, int xpos, int ypos);
	/**
	* Destruktor
	*/
	~Text();
	/**
	* Ustawia kolor tekstu, tresc tekstu i tworzy dla niego powierzchnie
	*/
	void Update(TTF_Font*font, SDL_Renderer * renderer);
private:
};
