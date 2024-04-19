#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <iostream>
#include "Hero.h"
#include "Menu.h"
using namespace sf;
using namespace std;

class Game {
	float offsetX = 0;
	float offsetY = 0;
	// работа с графической частью
	RenderWindow window;
	RectangleShape block;
	int height = 16;
	int width = 150;
	Hero hero;
	
	string map[16] = {"BBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBB",
					"B                                                                                                                                                    B",
					"B                                                                                                                                                    B",
					"B                                                                                                                                                    B",
					"B                                                                                                                                                    B",
					"B                                                                                                                                                    B",
					"B                                                                                                                                                    B",
					"B                                                                                                                                                    B",
					"B                                                                                                                                                    B",
					"B                                                                                                                                                    B",
					"B                                                                                                                                                    B",
					"B                                                                                                                                                    B",
					"B                                      00                                                   00                                                       B",
					"B                                      00              00                                   00              00                                       B",
					"BBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBB",
					"BBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBB"};

	Menu menu;
	// работа со звуком
	Music music;
	// работа с временем
	Clock clock;
	
public:
	Game();
	void run();
	void update(float time);
	void processEvent();
	void render();

	string* getMap();
};