#include "Game.h"

Game::Game(RenderWindow* window) : 
	window(window),
	block(sf::Vector2f(16, 16))
{
	block.setOutlineThickness(1); 
}

void Game::run()
{
	while(window->isOpen()) 
	{
		// ������ � ��������
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
		
	}
	if (Keyboard::isKeyPressed(Keyboard::Right)) // ������
			hero.setAcceleX(0.1);
	if (Keyboard::isKeyPressed(Keyboard::Left))  // �������
			hero.setAcceleX(-0.1);

	if (Keyboard::isKeyPressed(Keyboard::Up))	 // �����
	{
		if (hero.getOnGround()) {
			hero.setAcceleY(-0.27);
			hero.setOnGround(false);
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
	// �� ����� � ������ ���
	window->clear(Color(10, 10, 10, 255));
	
	// ������ ������� ����� ���� � ���������� ���
	for (int i = 0; i < height; i++) {
		for (int j = 0; j < width; j++) {

			if (map[i][j] == 'B') 
			{
				block.setFillColor(Color::Black);
				block.setOutlineColor(Color::Blue);
			}
			if (map[i][j] == 'R') 
			{
				block.setFillColor(Color::Black);
				block.setOutlineColor(Color::Red);
			}
			if (map[i][j] == '0')
			{
				block.setFillColor(Color::Black);
				block.setOutlineColor(Color::White);
			}
			if (map[i][j] == ' ')
				continue;

			block.setPosition(j * 16 - offsetX, i * 16 - offsetY);
			window->draw(block);
		}
	}

	// ���������� �����
	window->draw(hero.getHero());

	// ������ �� ��� �� �����
	window->display();
}

string* Game::getMap()
{
	return map;
}
