#include "Game.h"

Game::Game(RenderWindow* window) : 
	window(window),
	block(sf::Vector2f(16, 16))
{
	hero("img/Mario_tileset.png");
}

void Game::run()
{
	//menu.run(window);   // меню
	//music.stop(); // музыка

	// игра
	while(window->isOpen()) 
	{
		// работа с временем
		float time = clock.getElapsedTime().asMicroseconds();
		clock.restart();
		time /= 800;
		if (time > 20)
			time = 20;

		processEvent();
		update(time);
		render();
	}
}

void Game::processEvent()
{
	Event event;
	while (window->pollEvent(event)) 
	{
		if (event.type == Event::Closed)
			window->close();
		if (Keyboard::isKeyPressed(Keyboard::Right)) // налево
			hero.setAcceleX(0.1);
		if (Keyboard::isKeyPressed(Keyboard::Left))  // направо
			hero.setAcceleX(-0.1);
		if (Keyboard::isKeyPressed(Keyboard::Up))	 // вверх
		{
			if (hero.getOnGround()) {
				hero.setAcceleY(-0.27);
				hero.setOnGround(false);
			}
		}
	}
}

void Game::update(float time)
{
	hero.update(time, offsetX, offsetY, map); // float& time, float& offsetX, float& offsetY, String* map[]

	if (hero.getRect().left > 200)
		offsetX = hero.getRect().left - 200;
}

void Game::render()
{
	// всё стёрли и задали фон
	window->clear(Color(50, 50, 50, 255));
	
	// задали каждому блоку цвет и нарисовали его
	for (int i = 0; i < height; i++) {
		for (int j = 0; j < width; j++) {
			block.setOutlineThickness(1);

			if (map[i][j] == 'B') {
				block.setFillColor(Color::Black);
				block.setOutlineColor(Color::Cyan);

			}
			if (map[i][j] == '0')
			{
				block.setFillColor(Color::White);
				block.setOutlineColor(Color::Red);
			}
			if (map[i][j] == ' ')
				continue;
			block.setPosition(j * 16 - offsetX, i * 16 - offsetY);
			window->draw(block);
		}
	}

	// нарисовали героя
	window->draw(hero.getSprite());

	// вывели всё это на экран
	window->display();
}

string* Game::getMap()
{
	return map;
}
