#pragma once
#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H

#include "game.hpp"

/**
* Klasa GameObject jest odpowiedzialna za wszystkie elementy znajdujace sie w grze, dziedzicza po niej klasy, tworzace obiekty w grze
*/
class GameObject
{
public:
	/**
	* Konstruktor argumentowy
	* @param texturesheet Sciezka do grafiki
	* @param x Pozycja x na ekranie
	* @param y Pozycja y na ekranie
	*/
	GameObject(const char* texturesheet, int x, int y);
	/**
	* Destruktor
	*/
	~GameObject();
	/**
	* Konstruktor bezargumentowy
	*/
	GameObject();

	/**
	* Metoda Update() jest metoda wirtualna odpowiadajaca za zapewnienie poprawnej obslugi wywolan metod w klasach pochodnych
	*/
	virtual void Update();
	/**
	* Metoda Render() odpowiada za renderowanie struktur
	*/
	void Render(); 
	/**
	* Metoda isCollide() zwraca wartosc true, gdy obiekty w grze zkoliduja sie
	* @param destRectt Pozycja danego obiektu
	* @param size1 Rozmiar pierwszego kolidujacego obiektu
	* @param size2 Rozmiar drugiego kolidujacego obiektu 
	*/
	bool isCollide(SDL_Rect destRectt, int size1, int size2);
	/**
	* Pozycja x na ekranie
	*/
	int xpos;
	/**
	* Pozycja y na ekranie
	*/
	int ypos;
	/**
	*  Textura objektu
	*/
	SDL_Texture* objTexture;
	/**
	* struktura reprezentujaca prostokat zrodlowy tekstury
	*/
	SDL_Rect srcRect;
	/**
	* struktura reprezentujaca prostokat wyswietlany na ekranie tekstury
	*/
	SDL_Rect destRect;
	
private:
};

#endif