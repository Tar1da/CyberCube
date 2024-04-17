#include "Game.h"

Game::Game() :
	window(VideoMode(400, 250), "Mario")
{
	tiles.loadFromFile("Mario_Tileset.png");
	mario.set(tiles);
	mushroom.set(tiles, 48 * 16, 13 * 16);
	tile.setTexture(tiles);
	//работа со звуком
	buf.loadFromFile("Jump.ogg");
	music.openFromFile("Mario_Theme.ogg");
	sound.setBuffer(buf);
}

void Game::run()
{
	music.play();
	while (window.isOpen())
	{	
		float time = clock.getElapsedTime().asMicroseconds();
		clock.restart();

		time = time / 500;  // здесь регулируем скорость игры

		if (time > 20) time = 20;
		processEvent();

		if (mario.rect.intersects(mushroom.rect))
		{
			if (mushroom.life) {
				if (mario.dy > 0) {
					mushroom.dx = 0;
					mario.dy = -0.2;
					mushroom.life = false; }
				else 
					mario.sprite.setColor(Color::Red);
			}
		}


		if (mario.rect.left > 200) map.offset_x = mario.rect.left - 200; //смещение

		update(time);
		render();
	}
}

void Game::update(float& time)
{
	mario.update(time);
	mushroom.update(time);
}

void Game::processEvent()
{
		Event event;
		while (window.pollEvent(event))
		{
			if (event.type == Event::Closed)
				window.close();
		}

		if (Keyboard::isKeyPressed(Keyboard::Left))    
			mario.dx = -0.1;

		if (Keyboard::isKeyPressed(Keyboard::Right))    
			mario.dx = 0.1;

		if (Keyboard::isKeyPressed(Keyboard::Up))	
			if (mario.onGround) {
				mario.dy = -0.27;
				mario.onGround = false;
				sound.play(); 
			}
}

void Game::render()
{
	window.clear(Color::Blue);

		for (int i = 0; i < map.height; i++)
			for (int j = 0; j < map.width; j++)
			{	// дорога
				if (map.map[i][j] == 'P')  tile.setTextureRect(IntRect(143 - 16 * 3, 112, 16, 16));
				// блок
				if (map.map[i][j] == 'k')  tile.setTextureRect(IntRect(143, 112, 16, 16));
				// блок-вопрос
				if (map.map[i][j] == 'c')  tile.setTextureRect(IntRect(143 - 16, 112, 16, 16));
				// трубa
				if (map.map[i][j] == 't')  tile.setTextureRect(IntRect(0, 47, 32, 95 - 47));
				//облакo
				if (map.map[i][j] == 'w')  tile.setTextureRect(IntRect(99, 224, 140 - 99, 255 - 224));
				//фон
				if ((map.map[i][j] == ' ') || (map.map[i][j] == '0')) continue;

				tile.setPosition(j * 16 - map.offset_x, i * 16 - map.offset_y);
				window.draw(tile);
			}

		window.draw(mario.sprite);
		window.draw(mushroom.sprite);

		window.display();
}
