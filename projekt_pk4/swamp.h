#pragma once

#pragma once

#include "game.hpp"
#include "GameObject.h"
/**
* Klasa Swamp tworzy obiekt blota, ktore spowalnia gracza. Dziedziczy po klasie GameObject
*/
class Swamp :public GameObject
{
public:
	/**
	* Kostruktor argumentowy
	* @param texturesheet Sciezka do grafiki
	* @param x Pozycja x na ekranie
	* @param y Pozycja y na ekranie
	*/
	Swamp(const char* texturesheet, int x, int y);
	/**
	* Destruktor
	*/
	~Swamp();
	/**
	* Metoda Update() sluzy do aktualizowania pozycji blota na ekranie
	*/
	void Update();

private:
};

