#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include "Game.h"
#include "Menu.h"
using namespace sf;
using namespace std;

int main() {
	RenderWindow window(VideoMode(800, 600), "Platformer )");

	//Menu menu(&window);
	//menu.run();

	Game game(&window);
	game.run();

	return 0;
}

//Фон меню
//<a href = "https://ru.freepik.com/free-vector/technological-dark-background_958584.htm#fromView=search&page=3&position=44&uuid=7489b471-a80b-4c0e-9226-e68c2e4fd7d8">Изображение от Harryarts на Freepik< / a>