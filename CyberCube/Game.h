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
	RenderWindow* window;
	RectangleShape block;
	int height = 16;
	int width = 150;
	Hero hero;
	
	string map[16] = {"BBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBB",
					  "B                                                                                                                                                    B",
					  "B                                                                                                                                                    B",
					  "B                               RBRBRBR                                                                                                              B",
					  "B                                                                                                                                                    B",
					  "B                          BBBBBBBBBBBBBBBBBR                                                                                                        B",
					  "B                        0B                  B                                                                                                       B",
					  "B0                      0B                    R                                   00                                                                 B",
					  "BBB                     B                      B                                  BB                                                                 B",
					  "B                      B                        B                               0RRRR0                                                               B",
					  "B   BRBBB                                        R                             BBBBBBBB                                                              B",
					  "B                              0 0 0 0 0          R						    0RRRRRRRRRR0                                                            B",
					  "B             BBBBB                                R              0       BBBBBBBBBBBBBBBBB                                                          B",
					  "B           B0                                      BBBBBBB     R          000RRRRRRRRR000                                                           B",
					  "BBBBBBBBBBBBBBBBBBBBBBBBBBBRBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBB",
					  "BBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBB"};


	// работа со звуком
	// Music music;
	// работа с временем
	Clock clock;
	
public:
	Game(RenderWindow* window);
	void run();
	void update(float time);
	void processEvent();
	void render();

	string* getMap();
};