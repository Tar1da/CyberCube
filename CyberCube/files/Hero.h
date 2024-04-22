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
	RectangleShape hero;
	FloatRect rect;
	//Texture texture;
	//Sprite sprite;
public:
	Hero();
	void update(float time, float offsetX, float offsetY, string map[]);
	void collision(int dir, string map[]);

	void setOnGround(bool onGround);
	void setAcceleX(float acceleX);
	void setAcceleY(float acceleY);
	
	FloatRect getRect();
	bool getOnGround();
	RectangleShape getHero();
};