//#pragma once
#ifndef game_hpp
#define game_hpp

#include <SDL.h>
#include <SDL_image.h>
#include <iostream>
#include "GameObject.h"

/** 
* Klasa Game odpowiada za inicjowanie gry, odswiezanie jej zawartosci, operowanie wydarzeniami, renderowaniem tekstur oraz za czyszczenie zawartosci po zakonczeniu rozgrywki
*/ 
class Game
{
public:
	/**
	* Konstruktor bezargumentowy
	*/
	Game();
	/**
	* Destruktor
	*/
	~Game();

	/**
	* Metoda init() odpowiada za inicjowanie wszystkich tekstur, na odpowiednim miejscu na ekranie
	* @param title Nazwa pliku zrodlowego
	* @param xpos Pozycja x na ekranie
	* @param ypos Pozycja y na ekranie
	* @param width Szerokosc generowanej struktury
	* @param height Wysokosc generowanej struktury
	* @param fullscreen Pelny ekran lub okienkowy
	*/
	void init(const char* title, int xpos, int ypos, int width, int height, bool fullscreen);
	/**
	* Metoda handleEvents() wykonuje odpowiednia operacje w zaleznosci od tego co wydarzylo sie podczas rozgrywki
	*/
	void hanleEvents();
	/**
	* Metoda update() odswieza pozycje tekstur na ekranie
	*/
	void update();
	/**
	* Metoda render() renderuje tekstury
	*/
	void render();
	/**
	* Metoda clean() czysci zawartosc gry po zakonczeniu rozgrywki
	*/
	void clean();
	/**
	* Metoda running() zmienia wartosc zmiennej isRunning
	*/
	bool runnig()
	{
		return isRunning;
	}

	/**
	* @param renderer Renderer tekstur
	*/
	static SDL_Renderer *renderer;
	/**
	* @param isRunning Zmienna odpowiadajaca za wylaczanie gry
	*/
	bool isRunning;
	/**
	* @param window Tworzy okno
	*/
	SDL_Window* window;

private:

};

#endif
