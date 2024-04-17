#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <iostream>
#include "Map.h"
using namespace sf;
using namespace std;

class Player {

public:
	float dx, dy;
	FloatRect rect;
	bool onGround;
	Sprite sprite;
	float frame;
	Map map;

	void set(Texture& image);
	void update(float time);
	void Collision(int num);
};