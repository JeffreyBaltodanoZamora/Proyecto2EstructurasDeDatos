#include "Partida.h"

void main(int argc, char** argv[]) {
	sf::RenderWindow window(sf::VideoMode(640, 480), "Proyecto 1");
	Menu menu(window.getSize().x, window.getSize().y);
	bool menuVisible = true;

	while (window.isOpen()) {

		sf::Event event;
		while (window.pollEvent(event)) {
			if (event.type == sf::Event::Closed) {
				window.close();
			}
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
				menu.MoveUp();
			}
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
				menu.MoveDown();
			}
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space)) {
				int a = menu.GetPressedItem();
				if (a == 0) {
					Partida partida;
					window.clear(sf::Color::White);
					partida.nuevaPartidaJvJ();
					break;
				}
				else if (a == 1) {
				}
				else {
					window.close();
				}
			}
		}

		//if (menuVisible) {
		window.clear(sf::Color::White);
		menu.draw(window);
		//}
		window.display();
	}
}