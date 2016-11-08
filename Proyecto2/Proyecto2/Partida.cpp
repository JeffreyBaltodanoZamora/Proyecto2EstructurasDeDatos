#include "Partida.h"

Partida::Partida() : m_window("Sokoban", sf::Vector2u(800, 600))
{
	if (!(texturaFondo.loadFromFile("fondo.png") && (texturaO.loadFromFile("O.png")) && (texturaX.loadFromFile("x.png")))) {
		cout << "Error al cargar texturas." << endl;
	}
}

Partida::~Partida()
{

}

void Partida::nuevaPartidaJvJ() {
	
	while (!m_window.haTerminado()) {
		m_window.actualizar();
		m_window.limpiar();
		agregaTexturasEscenario(m_window);
		manejarEntrada();
		m_window.desplegar();
		/*if (nivelCompleto()) {
			m_window.limpiar();
			subMenuNivel();
		}*/
	}
}

int Partida::subMenuNivel() {
	bool eleccion = false;
	int a = menu.getCharacterSize();
	font.loadFromFile("arial.ttf");
	menu.setFont(font);
	menu.setColor(sf::Color::Blue);

	menu.setString("Facil (a)");
	menu.setPosition(sf::Vector2f(540 / 2, 480 / (MAX_NUMBER_OF_ITEMS + 1) * 1));
	m_window.dibujar(menu);

	menu.setString("Normal (s)");
	menu.setPosition(sf::Vector2f(540 / 2, 480 / (MAX_NUMBER_OF_ITEMS + 1) * 2));
	m_window.dibujar(menu);

	menu.setString("Dificil (d)");
	menu.setCharacterSize(a);
	menu.setPosition(sf::Vector2f(540 / 2, 480 / (MAX_NUMBER_OF_ITEMS + 1) * 3));
	m_window.dibujar(menu);

	m_window.desplegar();
	while (!eleccion) {
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
			eleccion = true;
		}
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {
			eleccion = true;
		}
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
			eleccion = true;
		}
	}
	return 0;
}

void Partida::agregaTexturasEscenario(Window &window) {
	sf::Sprite sprite;
	sprite.setTexture(texturaFondo);
	sprite.setScale(2, 1.5);
	sprite.setPosition(0, 0);
	window.dibujar(sprite);
	
	//x aqui para abajo
	sprite.setScale(0.5, 0.5);
	sprite.setTexture(texturaX);
	window.dibujar(sprite);
}

void Partida::manejarEntrada() {
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
		
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
		
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
		
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
		
	}
}

bool Partida::nivelCompleto() {
	if (true) 
	{
		return true;
	}
	return false;
}