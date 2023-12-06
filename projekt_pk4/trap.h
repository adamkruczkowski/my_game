#pragma once


#include "game.hpp"
#include "GameObject.h"
/**
* Klasa Trap tworzy obiekt pulapki. Gdy gracz w nia wejdzie, przegrywa. Dziedziczy po klasie GameObject
*/
class Trap:public GameObject
{
public:
	/**
	* Kostruktor argumentowy
	* @param texturesheet Sciezka do grafiki
	* @param x Pozycja x na ekranie
	* @param y Pozycja y na ekranie
	*/
	Trap(const char* texturesheet, int x, int y);
	/**
	* Destruktor
	*/
	~Trap();
	/**
	* Metoda Update() sluzy do aktualizowania pozycji blota na ekranie
	*/
	void Update();

private:
};
