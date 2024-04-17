#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <iostream>
#include "Player.h"
#include "Enemy.h"
#include "Map.h"
using namespace sf;
using namespace std;

class Game {
	RenderWindow window;
	Texture tiles;
	Player mario;
	Enemy mushroom;
	Sprite tile;
	Map map;
	//������ �� ������
	SoundBuffer buf;
	Sound sound;
	Music music;
	//������ � ��������
	Clock clock;
public:
	Game();
	void run();
	void update(float& time);
	void processEvent();
	void render();
};