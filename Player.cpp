#include "Player.h"

void Player::set(Texture& image)
{
	sprite.setTexture(image);
	rect = FloatRect(25, 180, 16, 16);
	dx = 0.1;
	dy = 0.1;
	frame = 0;
}

void Player::update(float time)
{
	rect.left += dx * time;
	Collision(0);

	if (!onGround)
		dy = dy + 0.0005 * time;
	rect.top += dy * time;
	onGround = false;
	Collision(1);

	frame += time * 0.005;
	if (frame > 3)
		frame -= 3;

	if (dx > 0) 
		sprite.setTextureRect(IntRect(112 + 31 * int(frame), 144, 16, 16));
	if (dx < 0) 
		sprite.setTextureRect(IntRect(112 + 31 * int(frame) + 16, 144, -16, 16));

	sprite.setPosition(rect.left - map.offset_x, rect.top - map.offset_y);
	dx = 0;
}

void Player::Collision(int num)
{
	for (int i = rect.top / 16; i < (rect.top + rect.height) / 16; i++)
		for (int j = rect.left / 16; j < (rect.left + rect.width) / 16; j++)
		{
			if ((map.map[i][j] == 'P') || (map.map[i][j] == 'k') || (map.map[i][j] == '0') || (map.map[i][j] == 'r') || (map.map[i][j] == 't'))
			{
				if (dy > 0 && num == 1)
				{
					rect.top = i * 16 - rect.height;  
					dy = 0;   
					onGround = true;
				}
				if (dy < 0 && num == 1)
				{
					rect.top = i * 16 + 16;   
					dy = 0;
				}
				if (dx > 0 && num == 0)
				{
					rect.left = j * 16 - rect.width;
				}
				if (dx < 0 && num == 0)
				{
					rect.left = j * 16 + 16;
				}
			}

			if (map.map[i][j] == 'c') {
				map.map[i][j] = ' ';
			}
		}
}
