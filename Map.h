#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <iostream>
using namespace sf;
using namespace std;

class Map {
public:
	int height;
	int width;
	float offset_x;
	float offset_y;
	String* map;
	Map();
};


