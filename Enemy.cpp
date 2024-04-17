#include "Enemy.h"

void Enemy::set(Texture& image, int x, int y)
{
	sprite.setTexture(image);
	rect = FloatRect(x, y, 16, 16);

	dx = 0.05;
	frame = 0;
	life = true;
}

void Enemy::update(float time)
{
	rect.left += dx * time;

	Collision();


	frame += time * 0.005;
	if (frame > 2) 
		frame -= 2;

	sprite.setTextureRect(IntRect(18 * int(frame), 0, 16, 16));

	if (!life) 
		sprite.setTextureRect(IntRect(58, 0, 16, 16));

	sprite.setPosition(rect.left - map.offset_x, rect.top - map.offset_y);
}

void Enemy::Collision()
{
	for (int i = rect.top / 16; i < (rect.top + rect.height) / 16; i++)
		for (int j = rect.left / 16; j < (rect.left + rect.width) / 16; j++) {
			if ((map.map[i][j] == 'P') || (map.map[i][j] == '0'))
			{
				if (dx > 0)
				{
					rect.left = j * 16 - rect.width; dx *= -1;
				}
				else if (dx < 0)
				{
					rect.left = j * 16 + 16;  dx *= -1;
				}
			}
		}
}
