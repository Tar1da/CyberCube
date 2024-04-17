#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <iostream>
#include "Map.h"
using namespace sf;
using namespace std;

class Enemy
{
public:
	float dx, dy;
	FloatRect rect;
	Sprite sprite;
	float frame;
	bool life;
	Map map;

	void set(Texture& image, int x, int y);
	void update(float time);
	void Collision();
};