#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
using namespace sf;
using namespace std;

class Hero {
	float acceleX = 0.1;
	float acceleY = 0.1;
	float frame = 0;
	bool onGround = true;
	FloatRect rect;
	Texture texture;
	Sprite sprite;
	//string* map = nullptr;
public:
	Hero();
	Hero(string img);
	void operator()(string img);
	void update(float time, float offsetX, float offsetY, string map[]);
	void collision(int dir, string map[]);

	FloatRect getRect();
	Sprite getSprite();
	bool getOnGround();
	void setOnGround(bool onGround);
	//float getAcceleX() {};
	//float getAcceleY() {};
	void setAcceleX(float acceleX);
	void setAcceleY(float acceleY);
};