#include "game.hpp"
#include "TextureManager.hpp"
#include "enemy.h"
#include "Mapa1.hpp"
#include "player.hpp"
#include "trap.h"
#include "health.h"
#include <cstdlib>
#include <vector>
#include "GameObject.h"
#include "text.h"
#include "winscreen.h"
#include <windows.h>
#include <thread>
#include <regex>
#include <filesystem>
#include <string>
#include <fstream>
#include "swamp.h"
/**
* Importuje z modulu zmienne
*/
import zmienne;

/**
* Obiekt tworzacy postac gracza
*/
Player* player;
/**
* Obiekt inicjujacy 1 poziom
*/
Map* map1;
/**
* Obiekt inicjujacy 2 poziom
*/
Map* map2;
/**
* Obiekt inicjujacy 3 poziom
*/
Map *map3;
/**
* Tablica przeciwnikow z 1 poziomu 
*/
Enemy* enemy[4];
/**
* Tablica przeciwnikow z 2 poziomu
*/
Enemy* enemy2[4];
/**
* Tablica przeciwnikow z 3 poziomu
*/
Enemy* enemy3[5];
/**
* Finalna postac, jezeli z nia skolidujemy wygrywamy gre
*/
Enemy *princess;
/**
* Pulapki 1 poziomu
*/
Trap* trap[2];
/**
* Pulapki 2 i 3 poziomu
*/
Trap* trap2[2];
/**
* Serce leczace gracza
*/
Health* health;
/**
* Informacja o zwyciestwie
*/
Winscreen* winscreen;
/**
* Informacja o porazce
*/
Winscreen* losescreen;
/**
* Menu glowne
*/
Winscreen* menu;
/**
* Dynamiczny tekst informujacy o punktach zdrowia gracza
*/
Text* text;
/**
* Staly tekst o tresci "Win streak: "
*/
Text* text2;
/**
* Dynamiczny teskt informujacy o serii zwyciestw gracza
*/
Text*text3;
/**
* Bagno spowalniajace gracza
*/
Swamp* swamp;
/**
* Czcionka arial do wyswietlania tekstu
*/
TTF_Font* font1;
/**
* Licznik czasu od ostatniego teleportowania sie serca leczacego gracza
*/
Uint32 teleportTimer = 0;
/**
* Renderer
*/
SDL_Renderer* Game::renderer = nullptr;

namespace fs = std::filesystem;

Game::Game()
{};

Game::~Game()
{};
/**
* Funkcja intToString() zamienia zmienne typu int na char*
* @param data Zmienna, ktora chcemy zamienic z typu int na char*
*/
char* intToString(int data)
{
	std::string strData = std::to_string(data);
	char* temp = new char[strData.length() + 1];
	strcpy(temp, strData.c_str());

	return temp;
}
/**
* Funkcja checkTemplate() sprawdza poprawnosc zapisu sciezki do tekstury
* @param templatee Sciezka do tekstury
*/
bool checkTemplate(const char* templatee)
{
	std::regex reg("\\b\\w+\\.png\\b");
	return std::regex_match(templatee, reg);
}
/**
* Funkcja creatingFile() tworzy plik tekstowy, wczesniej sprawdzajac czy na dysku jest odpowiednia ilosc miejsca. Gdy plik tekstowy nie istnieje tworzy go
*/
void creatingFile()
{
	std::string fileName = "winStreak.txt";

	fs::space_info info = fs::space(fs::current_path());
	uintmax_t avaliableSpace = info.available;
	uintmax_t fileSize = 1024 * 1000;

	if (!fs::exists(fileName))
	{
		if (fileSize <= avaliableSpace)
		{
			std::string line;
			std::ofstream plik(fileName);
			plik << "0";
			plik.close();
			std::ifstream plik1(fileName);
			if (std::getline(plik1, line))
			{
				winStreak = std::stoi(line);
			}
			else
			{
				std::cout << "Error" << std::endl;
			}
			plik1.close();
			std::cout << winStreak << std::endl;
		}
	}
	else
	{
		std::string line;
		std::ifstream plik1(fileName);
		if (std::getline(plik1, line))
		{
			winStreak = std::stoi(line);
		}
		else
		{
			std::cout << "Error" << std::endl;
		}
		plik1.close();
		std::cout << winStreak << std::endl;
	}
}
/**
* Funkcja safeScore() zapisuje uzyskany przez gracza wynik do pliku tekstowego
*/
void safeScore()
{
	std::ofstream plik("winStreak.txt", std::ios::trunc);
	if (plik.is_open()) 
	{
		plik << winStreak << std::endl;
		plik.close();
	}
	else {
		std::cout << "Error" << std::endl;
	}
}

void Game::init(const char* title, int xpos, int ypos, int width, int height, bool fullscreen)
{
	TTF_Init();
	srand(time(NULL));

	int flags = 0;
	font1 = TTF_OpenFont("arial.ttf", 25);


	creatingFile();

	if (fullscreen)
	{
		flags = SDL_WINDOW_FULLSCREEN;
	}
	
	if (SDL_Init(SDL_INIT_EVERYTHING) == 0)
	{
		std::cout << "Inicjalizacja zakonczona pomyslnie" << std::endl;

		window = SDL_CreateWindow(title, xpos, ypos, width, height, flags);
		renderer = SDL_CreateRenderer(window, -1, 0);

		if (renderer)
		{
			SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
		}

		isRunning = true;
	}

	if (path1)
	{
		player = new Player(path1, 50, 50);
	}
	else
	{
		std::cout << "Invalid path";
	}

	if (path2)
	{
		for (int i = 0; i <= 3; i++)
		{
			enemy[i] = new Enemy(path2, (rand() % 600) + 165, (rand() % 400) + 165);
		}
	}
	else
	{
		std::cout << "Invalid path";
	}

	if (path3)
	{
		for (int i = 0; i <= 3; i++)
		{
			enemy2[i] = new Enemy(path3, -500, -500);
		}
	}
	else
	{
		std::cout << "Invalid path";
	}


	if (path4)
	{
		for (int i = 0; i <= 4; i++)
		{
			enemy3[i] = new Enemy(path4, -400, -400);
		}
	}
	else
	{
		std::cout << "Invalid path";
	}
	
	if (path5)
	{
		for (int i = 0; i <= 1; i++)
		{
			trap[i] = new Trap(path5, (rand() % 600) + 165, (rand() % 400) + 165);
		}
	}
	else
	{
		std::cout << "Invalid path";
	}

	if (path6)
	{
		for (int i = 0; i <= 1; i++)
		{
			trap2[i] = new Trap(path6, -500, -500);
		}
	}
	else
	{
		std::cout << "Invalid path";
	}

	if (path7)
	{
		health = new Health(path7, 200, 200);
	}
	else
	{
		std::cout << "Invalid path";
	}

	winStreak1 = intToString(winStreak);
	
	text = new Text(renderer, "100", font1, 350, 550);
	text2 = new Text(renderer, "Win streak: ", font1, 250, 550);
	text3 = new Text(renderer, winStreak1, font1, 540, 550); 

	std::string cw ="Win streak: ";
	text2->destRect.w = cw.size() * 25;

	std::string cw1 =winStreak1;
	text3->destRect.w = cw1.size() * 25;

	std::string stuwa = "100";
	text->destRect.w = stuwa.size() * 25;

	if (path8)
	{
		princess = new Enemy(path8, -500, -500);
	}
	else
	{
		std::cout << "Invalid path";
	}

	if (path9)
	{
		winscreen = new Winscreen(path9, 0, 0);
	}
	else
	{
		std::cout << "Invalid path";
	}

	if (path10)
	{
		losescreen = new Winscreen(path10, 0, 0);
	}
	else
	{
		std::cout << "Invalid path";
	}

	if (path11)
	{
		menu = new Winscreen(path11, 0, 0);
	}
	else
	{
		std::cout << "Invalid path";
	}
	if (path12)
	{
		swamp = new Swamp(path12, (rand() % 600) + 165, (rand() % 400) + 165);
	}
	else
	{
		std::cout << "Invalid path";
	}

	map1 = new Map(1);
	map2 = new Map(2);
	map3 = new Map(3);

}
/**
* Funkcja initAfterLose() ustawia na nowo pozycje wszystkich tekstur na ekranie po przegranej gracza
*/
void initAfterLose()
{
	player->destRect.x = 50;
	player->destRect.y = 50;

	for (int i = 0; i <= 3; i++)
	{
		enemy[i]->destRect.x = (rand() % 600) + 165;
		enemy[i]->destRect.y = (rand() % 400) + 165;
	}
	for (int i = 0; i <= 3; i++)
	{
		enemy2[i]->destRect.x = -500;
		enemy2[i]->destRect.y = -500;
	}
	for (int i = 0; i <= 3; i++)
	{
		enemy3[i]->destRect.x = -500;
		enemy3[i]->destRect.y = -500;
	}
	for (int i = 0; i <= 1; i++)
	{
		trap[i]->destRect.x = (rand() % 600) + 165;
		trap[i]->destRect.y = (rand() % 400) + 165;
	}
	for (int i = 0; i <= 1; i++)
	{
		trap2[i]->destRect.x = -500;
		trap2[i]->destRect.y = -500;
	}
	health->destRect.x = 200;
	health->destRect.y = 200;

	princess->destRect.x = -500;
	princess->destRect.y = -500;

	islvl1 = true, islvl2 = false, islvl3= false;
	player->hp = 100;
	cnt = 0;
}
/**
* Funkcja setCntTimeto0() zeruje licznik czasu
*/
void setCntTimeto0()
{
	cntTime = 0;
}

void Game::hanleEvents()
{

	SDL_Event event;
	SDL_PollEvent(&event);

	switch (event.type)
	{
	case SDL_QUIT:
		isRunning = false;
		break;
	case SDL_KEYDOWN:
		switch (event.key.keysym.sym)
		{
		case SDLK_RIGHT:
			player->mR = true;
			break;
		case SDLK_LEFT:
			player->mL = true;
			break;
		case SDLK_UP:
			player->mU = true;
			break;
		case SDLK_DOWN:
			player->mD = true;
			break;
		case SDLK_p:
			isMenu = false;
			break;
		case SDLK_q:
			isRunning = false;
			break;
		}
	break;
	case SDL_KEYUP:
		switch (event.key.keysym.sym)
		{
		case SDLK_RIGHT:
			player->mR = false;
			break;
		case SDLK_LEFT:
			player->mL = false;
			break;
		case SDLK_UP:
			player->mU = false;
			break;
		case SDLK_DOWN:
			player->mD = false;
			break;
		}
		break;
		default:
			break;
	}

	if (islvl1 == true)
	{
		if (player->destRect.x >= 700 && player->destRect.y >= 550 && cnt == 4)
		{
			cnt = 0;
			islvl1 = false;
			islvl2 = true;
			for (int i = 0; i <= 3; i++)
			{
				enemy[i]->destRect.x = -500;
				enemy[i]->destRect.y = -500;
			}
			for (int i = 0; i <= 1; i++)
			{
				trap[i]->xpos = -500;
				trap[i]->ypos = -500;
			}
			for (int i = 0; i <= 3; i++)
			{
				enemy2[i]->destRect.x = (rand() % 600) + 165;
				enemy2[i]->destRect.y = (rand() % 400) + 165;
			}
			for (int i = 0; i <= 1; i++)
			{
				trap2[i]->xpos = (rand() % 600) + 165;
				trap2[i]->ypos = (rand() % 400) + 165;
			}
		}
	}
	if (islvl2 == true)
	{
		if (player->destRect.x <= 64 && player->destRect.y >= 550 && cnt == 4)
		{
			cnt = 0;
			islvl2 = false;
			islvl3 = true;
			for (int i = 0; i <= 4; i++)
			{
				enemy3[i]->destRect.x = (rand() % 600) + 165;
				enemy3[i]->destRect.y = (rand() % 400) + 165;
			}
			for (int i = 0; i <= 1; i++)
			{
				trap2[i]->xpos = (rand() % 600) + 165;
				trap2[i]->ypos = (rand() % 400) + 165;
			}
		}
	}

	for (int i = 0; i <= 3; i++)
	{
		if (enemy[i]->isCollide(player->destRect,32,32))
		{
			enemy[i]->destRect.x = -500;
			enemy[i]->destRect.y = -500;
			enemy[i]->isChasing = false;
			player->hp -= 33;
			hpNew = intToString(player->hp);
			text->writeText = hpNew;
			std::string hpNew1 = hpNew;
			text->destRect.w = hpNew1.size() * 25;
			text->Update(font1, renderer);
			cnt++;
		}
	}
	for (int i = 0; i <= 3; i++)
	{
		if (enemy2[i]->isCollide(player->destRect,32,32))
		{
			enemy2[i]->destRect.x = -500;
			enemy2[i]->destRect.y = -500;
			enemy2[i]->isChasing = false;
			player->hp -= 33;
			hpNew = intToString(player->hp);
			text->writeText = hpNew;
			std::string hpNew1 = hpNew;
			text->destRect.w = hpNew1.size() * 25;
			text->Update(font1, renderer);
			cnt++;
		}
	}
	for (int i = 0; i <= 4; i++)
	{
		if (enemy3[i]->isCollide(player->destRect, 32, 32))
		{
			enemy3[i]->destRect.x = -500;
			enemy3[i]->destRect.y = -500;
			enemy3[i]->isChasing = false;
			player->hp -= 33;
			hpNew = intToString(player->hp);
			text->writeText = hpNew;
			std::string hpNew1 = hpNew;
			text->destRect.w = hpNew1.size() * 25;
			text->Update(font1, renderer);
			cnt++;
			if (cnt == 5)
			{
				princess->destRect.x = 100;
				princess->destRect.y = 100;
			}
		}
	}
	for (int i = 0; i <= 1; i++)
	{
		if (trap[i]->isCollide(player->destRect,64,32))
		{
			if (!isLose)
			{
				winStreak--;
			}
			isLose = true;		
			winStreak1 = intToString(winStreak);
			text3->writeText = winStreak1;
			std::string ws2= winStreak1;
			text->destRect.w = ws2.size() * 25;
			text3->Update(font1, renderer);
		}
	}
	for (int i = 0; i <= 1; i++)
	{
		if (trap2[i]->isCollide(player->destRect,64,32))
		{
			if (!isLose)
			{
				winStreak--;
			}
			isLose = true;
			winStreak1 = intToString(winStreak);
			text3->writeText = winStreak1;
			std::string ws2 = winStreak1;
			text->destRect.w = ws2.size() * 25;
			text3->Update(font1, renderer);
		}
	}
	for (int i = 0; i <= 3; i++)
	{
		if (enemy[i]->isCollide(player->destRect, 200, 200))
		{
			enemy[i]->isChasing = true;
		}
	}
	for (int i = 0; i <= 3; i++)
	{
		if (enemy2[i]->isCollide(player->destRect, 200, 200))
		{
			enemy2[i]->isChasing = true;
		}
	}
	for (int i = 0; i <= 4; i++)
	{
		if (enemy3[i]->isCollide(player->destRect, 200, 200))
		{
			enemy3[i]->isChasing = true;
		}
	}
	
	if (health->isCollide(player->destRect, 48, 48))
	{
		if ((player->hp + 50) > 100)
		{
			player->hp = 100;
			hpNew = intToString(player->hp);
			text->writeText = hpNew;
			std::string hpNew1 = hpNew;
			text->destRect.w = hpNew1.size() * 25;
			text->Update(font1, renderer);
		}
		else
		{
			player->hp += 50;
			hpNew = intToString(player->hp);
			text->writeText = hpNew;
			std::string hpNew1 = hpNew;
			text->destRect.w = hpNew1.size() * 25;
			text->Update(font1, renderer);
		}

		isHeartTeleported = true;
		teleportTimer = SDL_GetTicks();
		health->destRect.x = -500;
		health->destRect.y = -500;
	}
	std::cout << player->velocity;
	
	if (swamp->isCollide(player->destRect, 128, 64))
	{
		if (!isCollideWithSwamp)
		{
			isCollideWithSwamp = true;
			player->velocity /= 2;
		}
	}

	if (player->destRect.x + 32 <= swamp->destRect.x || player->destRect.x >= swamp->destRect.x + 128 || player->destRect.y + 32 <= swamp->destRect.y || player->destRect.y >= swamp->destRect.y + 128)
	{
		if (isCollideWithSwamp)
		{
			isCollideWithSwamp = false;
			player->velocity *= 2;
		}
	}


	if (isHeartTeleported) 
	{
		Uint32 currentTime = SDL_GetTicks();
		Uint32 elapsedTime = currentTime - teleportTimer;

		if (elapsedTime >= 2000) 
		{
			health->destRect.x = (rand() % 600) + 165;
			health->destRect.y = (rand() % 400) + 165;
			isHeartTeleported = false;
		}
	}

	if (player->hp <= 0)
	{
		player->hp = 100;
		isLose = true;
		winStreak--;
		winStreak1 = intToString(winStreak);
		text3->writeText = winStreak1;
		std::string ws2 = winStreak1;
		text->destRect.w = ws2.size() * 25;
		text3->Update(font1, renderer);
	}



	if (princess->isCollide(player->destRect, 32, 32))
	{
		princess->destRect.x = -500;
		isWin = true;
		winStreak++;
		winStreak1 = intToString(winStreak);
		text3->writeText = winStreak1;
		std::string ws2 = winStreak1;
		text->destRect.w = ws2.size() * 25;
		text3->Update(font1, renderer);
	}
}

void Game::update()
{
	if (isLose)
	{
		cntTime++;
	}
	if (cntTime > 288)
	{
		isMenu = true;
		std::thread t (initAfterLose);
		std::thread t2(setCntTimeto0);
		t.join();
		t2.join();
		isLose = false;
	}
	if (isWin)
	{
		cntTime++;
	}
	if (cntTime > 288)
	{
		isMenu = true;
		std::thread t(initAfterLose);
		std::thread t2(setCntTimeto0);
		t.join();
		t2.join();
		isWin = false;
	}
	player->Update();
	swamp->Update();
	health->Update();
	for (int i = 0; i <= 3; i++)
	{
		enemy[i]->Update(player->destRect);
	}
	for (int i = 0; i <= 3; i++)
	{
		enemy2[i]->Update(player->destRect);
	}
	for (int i = 0; i <= 4; i++)
	{
		enemy3[i]->Update(player->destRect);
	}
	for (int i = 0; i <= 1; i++)
	{
		trap[i]->Update();
	}
	for (int i = 0; i <= 1; i++)
	{
		trap2[i]->Update();
	}
	princess->Update(player->destRect);

}

void Game::render()
{
	SDL_RenderClear(renderer);

	if (isMenu)
	{
		menu->Render();
	}
	if (!isMenu)
	{
		if (islvl1)
		{
			map1->DrawMap();
		}
		if (islvl2)
		{
			map2->DrawMap();
		}
		if (islvl3)
		{
			map3->DrawMap();
		}
		swamp->Render();
		player->Render();
		for (int i = 0; i <= 1; i++)
		{
			trap[i]->Render();
		}
		for (int i = 0; i <= 1; i++)
		{
			trap2[i]->Render();
		}
		for (int i = 0; i <= 3; i++)
		{
			enemy[i]->Render();
		}
		for (int i = 0; i <= 3; i++)
		{
			enemy2[i]->Render();
		}
		for (int i = 0; i <= 4; i++)
		{
			enemy3[i]->Render();
		}
		princess->Render();
		health->Render();
		if (isWin)
		{
			winscreen->Render();
		}
		if (isLose)
		{
			losescreen->Render();
		}
		if (!isWin && !isLose && !isMenu)
		{
			text->Render();
		}	
	}
	if (isMenu || isWin || isLose)
	{
		text3->Render();
		text2->Render();
	}
	SDL_RenderPresent(renderer);
}

void Game::clean()
{
	SDL_DestroyWindow(window);
	SDL_DestroyRenderer(renderer);
	SDL_Quit();
	TTF_CloseFont(font1);
	TTF_Quit();
	safeScore();
	std::cout << "Zawartosc gry wyczyszczona" << std::endl;
}
