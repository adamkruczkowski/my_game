export module zmienne;
 /**
 * Zmienne eksporowane do klasy Game cpp w celu zachowania przejrzystosci plikow 
 */
export {
	/**
	* HP gracza zapisane jako tekst w celu wyswietlania go na ekranie
	*/
	char* hpNew;
	/**
	* seria zwyciestw gracza zapisana jako tekst w celu wyswietlania jej na ekranie
	*/
	char* winStreak1;
	/**
	* Licznik zabitych potworow, gdy osiagnie odpowiednia wartosc, gracz moze przejsc na nastepny poziom
	*/
	int cnt = 0;
	/**
	* Licznik czasu, potrzebny do liczenia go, gdy serce znika z ekranu na 2 sekundy
	*/
	int cntTime = 0;
	/**
	* Seria zwyciestw gracza
	*/
	int winStreak = 0;
	/**
	* Zmienna okreslajaca, czy serce zostalo przeniesione poza ekran
	*/
	bool isHeartTeleported = false;
	/**
	* Zmienna okreslajaca, czy gracza jest na 1 poziomie
	*/
	bool islvl1 = true;
	/**
	* Zmienna okreslajaca, czy gracza jest na 2 poziomie
	*/
	bool islvl2 = false;
	/**
	* Zmienna okreslajaca, czy gracza jest na 3 poziomie
	*/
	bool islvl3 = false;
	/**
	* Zmienna okreslajaca czy gracz wygral
	*/
	bool isWin = false;
	/**
	* Zmienna okreslajaca czy gracz przegral
	*/
	bool isLose = false;
	/**
	* Zmienna okreslajaca czy gracz nie zaczal jeszcze rozgrywki i znajduje sie w menu glownym
	*/
	bool isMenu = true;
	/**
	* Zmienna okreslajaca czy gracz wszedl w bagno
	*/
	bool isCollideWithSwamp = false;
	/**
	* Sciezka do grafiki gracza
	*/
	const char* path1 = "grafiki/player.png";
	/**
	* Sciezka do grafiki wroga z 1 poziomu
	*/
	const char* path2 = "grafiki/enemy.png";
	/**
	* Sciezka do grafiki wroga z 2 poziomu
	*/
	const char* path3 = "grafiki/enemy2.png";
	/**
	* Sciezka do grafiki wroga z 3 poziomu
	*/
	const char* path4 = "grafiki/enemy3.png";
	/**
	* Sciezka do grafiki pulapki z 1 poziomu
	*/
	const char* path5 = "grafiki/trap.png";
	/**
	* Sciezka do grafiki pulapki z 2 i 3 poziomu
	*/
	const char* path6 = "grafiki/lava.png";
	/**
	* Sciezka do grafiki serca
	*/
	const char* path7 = "grafiki/health.png";
	/**
	* Sciezka do grafiki ksiezniczki
	*/
	const char* path8 = "grafiki/princess.png";
	/**
	* Sciezka do grafiki ekranu zwyciestwa
	*/
	const char* path9 = "grafiki/winscreen.png";
	/**
	* Sciezka do grafiki ekranu porazki
	*/
	const char* path10 = "grafiki/losescreen.png";
	/**
	* Sciezka do ekranu grafiki menu glownego
	*/
	const char* path11 = "grafiki/menu.png";
	/**
	* Sciezka do grafiki blota
	*/
	const char* path12 = "grafiki/swamp.png";
}
