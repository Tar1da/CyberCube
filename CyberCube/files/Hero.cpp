#include "Hero.h"

Hero::Hero() : 
	hero(Vector2f(16, 16)),
	rect(FloatRect(50, 16, 16, 16))
{
}

void Hero::update(float time, float offsetX, float offsetY, string map[])
{
	rect.left += acceleX * time;
	collision(0, map);

	if (!onGround)
		acceleY = acceleY + 0.0005 * time;

	rect.top += acceleY * time;
	onGround = false;
	collision(1, map);

	hero.setPosition(rect.left - offsetX, rect.top - offsetY);
	acceleX = 0;
}

void Hero::collision(int dir, string map[])
{
	for (int i = rect.top / 16; i < (rect.top + rect.height) / 16; i++) {
		for (int j = rect.left / 16; j < (rect.left + rect.width) / 16; j++) {

			// герой ходит по букве
			if (map[i][j] == 'B') {

				// по оси x
				if ((acceleX > 0) && (dir == 0))
					rect.left = j * 16 - rect.width;

				if ((acceleX < 0) && (dir == 0))
					rect.left = j * 16 + 16;

				// по оси y
				if ((acceleY > 0) && (dir == 1))
				{
					rect.top = i * 16 - rect.height;
					acceleY = 0;
					onGround = true;
				}
				if ((acceleY < 0) && (dir == 1))
				{
					rect.top = i * 16 + 16;
					acceleY = 0;
				}
			}

			 //герой собирает цифру
			if (map[i][j] == '0')
				map[i][j] = ' ';
		}
	}
}

FloatRect Hero::getRect()
{
	return rect;
}

bool Hero::getOnGround()
{
	return onGround;
}

RectangleShape Hero::getHero()
{
	return hero;
}

void Hero::setOnGround(bool onGround)
{
	this->onGround = onGround;
}

void Hero::setAcceleX(float acceleX)
{
	this->acceleX = acceleX;
}

void Hero::setAcceleY(float acceleY)
{
	this->acceleY = acceleY;
}
