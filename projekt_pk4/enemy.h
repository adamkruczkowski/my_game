#pragma once

#include "game.hpp"
#include "GameObject.h"

/**
* Klasa Enemy tworzy obiekt wroga na ekranie. Dzieciczy po klasie GameObject
*/
class Enemy: public GameObject
{
public:
	/**
	* Konstruktor argumentowy
	* @param texturesheet Sciezka do grafiki
	* @param x Pozycja x na ekranie
	* @param y Pozycja y na ekranie
	*/
	Enemy(const char* texturesheet, int x, int y);
	/**
	* Destruktor
	*/
	~Enemy();
	/**
	* Metoda Update() aktualizuje pozycje przeciwnika na ekranie i oblicza najkrotsza droge do gracza
	* @param playerR Zmienna do sprawdzania kolizji z graczem
	*/
	void Update(SDL_Rect playerR);
	/**
	*  Odpowiada za gonienie gracza przez przeciwnika, zmienia wartosc na true, gdy gracz podejdzie odpowiednio blisko do wroga
	*/
	bool isChasing = false;

private:
};
