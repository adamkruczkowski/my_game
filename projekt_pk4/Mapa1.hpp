#pragma once
#include "game.hpp"
#include "GameObject.h"

/**
* Klasa Map tworzy mape, na ktorej znajduje sie gracz, przeciwnicy, bloto, oraz pulapki
*/
class Map
{
public:
	/**
	* Kostruktor argumentowy
	* @param lvl Poziom do wyswietlenia
	*/
	Map(int lvl);
	/**
	* Destruktor
	*/
	~Map();
	/**
	* Metoda LoadMap() laduje odpowiednia mape
	* @param tab Dwuwymiarowa tablica umozliwiajaca zrenderowanie odpowiedniego poziomu
	*/
	void LoadMap(int tab[20][25]);
	/**
	* Renderuje mape na ekranie
	*/
	void DrawMap();

private:

	/**
	* struktura reprezentujaca prostokat zrodlowy tekstury
	*/
	SDL_Rect src;
	/**
	* struktura reprezentujaca prostokat wyswietlany na ekranie tekstury
	*/
	SDL_Rect dest;
	/**
	* Tekstura trawy
	*/
	SDL_Texture* grass;
	/**
	* Tekstura wody
	*/
	SDL_Texture* water;
	/**
	* Tekstura piasku
	*/
	SDL_Texture* sand;
	/**
	* Tekstura przejscia na nastepny poziom
	*/
	SDL_Texture* trapdoor;
	/**
	* Tekstura kamienistej podlogi
	*/
	SDL_Texture* rockfloor;
	/**
	* Tekstura kamienistej podlogi z pochodnia
	*/
	SDL_Texture* rockfloortorch;
	/**
	* Dwuwymiarowa tablica umozliwiajaca zrenderowanie mapy
	*/
	int map[20][25];
};
