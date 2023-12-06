#pragma once

#include "game.hpp"
#include "GameObject.h"
/**
* Klasa Winscreen wyswielta ekran zwyciestwa, porazki, lub menu glowne
*/
class Winscreen :public GameObject
{
public:
	/**
	* Kostruktor argumentowy
	* @param texturesheet Sciezka do grafiki
	* @param x Pozycja x na ekranie
	* @param y Pozycja y na ekranie
	*/
	Winscreen(const char* texturesheet, int x, int y);
	/**
	* Destruktor
	*/
	~Winscreen();

private:
};
