#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
using namespace sf;
using namespace std;

class Menu {
	RenderWindow* window;
	Texture btn_1_Texture, btn_2_Texture, btn_3_Texture, rules_Texture, menu_Background;
	Sprite btn_1, btn_2, btn_3,
		rules, menu_BackGr;
	bool isMenu = true;
	int btn_Num = 0;
	// ������
	Music music;
	
public:
	Menu(RenderWindow* window) : window(window)
	{
		music.openFromFile("music/Lindsey Stirling - Underground.mp3");
	}
	void run() {
		music.play();

		// ��������
		btn_1_Texture.loadFromFile("����.png");
		btn_2_Texture.loadFromFile("�������.png");
		btn_3_Texture.loadFromFile("�����.png");
		rules_Texture.loadFromFile("�����_�������.png");
		menu_Background.loadFromFile("Background(800, 600).png");

		// �������
		btn_1.setTexture(btn_1_Texture);
		btn_2.setTexture(btn_2_Texture);
		btn_3.setTexture(btn_3_Texture);
		rules.setTexture(rules_Texture);
		menu_BackGr.setTexture(menu_Background);

		btn_1.setPosition(200, 170);
		btn_2.setPosition(200, 250);
		btn_3.setPosition(200, 330);
		menu_BackGr.setPosition(0, 0);

		while (isMenu) {						// ���� �����//
			btn_1.setColor(Color::White);
			btn_2.setColor(Color::White);
			btn_3.setColor(Color::White);
			btn_Num = 0;
	
			window->clear();
	
			if (IntRect(200, 170, 400, 60).contains(Mouse::getPosition(*window))) {
				btn_1.setColor(Color::Blue);
				btn_Num = 1;
			}
			if (IntRect(200, 250, 400, 60).contains(Mouse::getPosition(*window))) {
				btn_2.setColor(Color::Blue);
				btn_Num = 2;
			}
			if (IntRect(200, 330, 400, 60).contains(Mouse::getPosition(*window))) {
				btn_3.setColor(Color::Blue);
				btn_Num = 3;
			}
	
			if (Mouse::isButtonPressed(Mouse::Left)) {
				if (btn_Num == 1)
					isMenu = false;
	
				if (btn_Num == 2) {
					window->draw(menu_BackGr);
					window->draw(rules);
					window->display();
					while 
						(!Keyboard::isKeyPressed(Keyboard::Escape));
				}
				if (btn_Num == 3) {
					window->close();
					isMenu = false;
				}
			}				
			window->draw(menu_BackGr);
			window->draw(btn_1);
			window->draw(btn_2);
			window->draw(btn_3);
	
			window->display();
		}
	}
};

