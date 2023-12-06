#pragma once

#include "game.hpp"
#include "TextureManager.hpp"
#include "GameObject.h"


/**
* Klasa Player odpowiedzialna jest za utworzenie obiektu postaci sterowanej przez gracza. Dziedziczy po klasie GameObject
*/
class Player :public GameObject
{
public:
	/**
	* Kostruktor argumentowy
	* @param texturesheet Sciezka do grafiki
	* @param x Pozycja x na ekranie
	* @param y Pozycja y na ekranie
	*/
	Player(const char* texturesheet, int x, int y);
	/**
	* Destruktor
	*/
	~Player();
	/**
	* Metoda Update() odpowiedzialna jest za zmienianie pozycji postaci na ekranie w zaleznosci od wcisnietego przycisku na klawiaturze
	*/
	void Update();
	/**
	* Zmienna ta zmienia wartosc na true, gdy gracz nacisnie strzalke w gore
	*/
	bool mU;
	/**
	* Zmienna ta zmienia wartosc na true, gdy gracz nacisnie strzalke w dol
	*/
	bool mD;
	/**
	* Zmienna ta zmienia wartosc na true, gdy gracz nacisnie strzalke w prawo
	*/
	bool mR;
	/**
	* Zmienna ta zmienia wartosc na true, gdy gracz nacisnie strzalke w lewo
	*/
	bool mL;
	/**
	* Punkty zdrowia gracza. Gdy ich wartosc osiagnie 0, nastepuje porazka. Moga zostac wyleczone sercami
	*/
	int hp = 100;
	/**
	* Predkosc gracza
	*/
	int velocity = 2;

private:

};