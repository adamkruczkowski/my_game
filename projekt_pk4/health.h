#pragma once

#include "game.hpp"
#include "GameObject.h"

/**
* Klasa Health tworzy obiekt serca. Po zkolidowaniu z nim przez gracza, gracz leczy sie. Dziedziczy po klasie GameObject
*/
class Health:public GameObject
{
public:
	/**
	* Kostruktor argumentowy
	* @param texturesheet Sciezka do grafiki
	* @param x Pozycja x na ekranie
	* @param y Pozycja y na ekranie
	*/
	Health(const char* texturesheet, int x, int y);
	/**
	* Destruktor
	*/
	~Health();
private:
};

