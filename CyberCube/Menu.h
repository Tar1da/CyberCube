#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include "Hero.h"
using namespace sf;
using namespace std;

class Menu {
	Texture menuTexture1, menuTexture2, menuTexture3, rulesTexture, menuBackground;
	Sprite menu1, menu2, menu3,
		rules, menuBackGr;
	bool isMenu = true;
	int menuNum = 0;
	RenderWindow window;
public:
	Menu(){}
	void operator()(RenderWindow& window){
		// текстуры
		menuTexture1.loadFromFile("img/Btn_Play.png");
		menuTexture2.loadFromFile("img/Btn_Rules.png");
		menuTexture3.loadFromFile("img/Btn_Exit.png");
		rulesTexture.loadFromFile("img/GameRules.png");
		menuBackground.loadFromFile("img/Background(800, 600).png");

		// спрайты
		menu1.setTexture(menuTexture1);
		menu2.setTexture(menuTexture2);
		menu3.setTexture(menuTexture3);
		rules.setTexture(rulesTexture);
		menuBackGr.setTexture(menuBackground);
		menu1.setPosition(5, 5);
		menu2.setPosition(5, 35);
		menu3.setPosition(5, 65);
		menuBackGr.setPosition(0, 0);
	}
	void run() {
		while (isMenu) {
			menu1.setColor(Color::White);
			menu2.setColor(Color::White);
			menu3.setColor(Color::White);
			menuNum = 0;
	
			window.clear();
	
			if (IntRect(100, 30, 300, 50).contains(Mouse::getPosition(window))) {
				menu1.setColor(Color::Cyan);
				menuNum = 1;
			}
			if (IntRect(100, 90, 300, 50).contains(Mouse::getPosition(window))) {
				menu2.setColor(Color::Cyan);
				menuNum = 2;
			}
			if (IntRect(100, 150, 300, 50).contains(Mouse::getPosition(window))) {
				menu3.setColor(Color::Cyan);
				menuNum = 3;
			}
	
			if (Mouse::isButtonPressed(Mouse::Left)) {
				if (menuNum == 1)
					isMenu = false;
	
				if (menuNum == 2) {
					window.draw(rules);
					window.display();
					while (!Keyboard::isKeyPressed(Keyboard::Escape));
				}
				if (menuNum == 3) {
					window.close();
					isMenu = false;
				}
	
				window.draw(menuBackGr);
				//window.draw(menu1);
				//window.draw(menu2);
				//window.draw(menu3);
	
				window.display();
	
			}
		}
	}
};

