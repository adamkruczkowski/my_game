#include "game.hpp"
/**
* Obiekt inicjujacy gre
*/
Game* game = nullptr;
/**
* Klasa glowna programu odpowiada za ustawienie ilosci klatek na sekunde i metod klasy Game
*/
int main(int argc, char *argv[])
{
	/**
	* @param FPS Klatki na sekunde
	*/
	const int FPS = 144;
	/**
	* @param frameDelay Opoznienie klatek
	*/
	const int frameDelay = 1000 / FPS;
	/**
	* @param frameStart Zainicjowanie klatek
	*/
	Uint32 frameStart;
	/**
	* @param frameTime Czas klatek
	*/
	int frameTime;

	game = new Game();

	game->init("GRA", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 800, 640, 0);

	while(game->runnig())
	{
		frameStart = SDL_GetTicks();

		game->hanleEvents();	
		game->render();
		game->update();

		frameTime = SDL_GetTicks() - frameStart;

		if (frameDelay > frameTime)
			SDL_Delay(frameDelay - frameTime);
	}

	game->clean();

	return 0;
}