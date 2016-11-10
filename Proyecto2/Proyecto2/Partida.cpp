#include "Partida.h"

Partida::Partida() : m_window("Gato", sf::Vector2u(800, 600))
{
	if (!(texturaFondo.loadFromFile("fondo.png") && (texturaO.loadFromFile("O.png")) && (texturaX.loadFromFile("x.png")))) {
		cout << "Error al cargar texturas." << endl;
	}
	sprite.setScale(1, 1);
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
		if (!nivelCompleto()) {
			m_window.limpiar();
			subMenuNivel();
		}
	}
}

int Partida::subMenuNivel() {
	bool eleccion = false;
	int a = menu.getCharacterSize();
	font.loadFromFile("arial.ttf");
	menu.setFont(font);
	menu.setColor(sf::Color::Blue);

	menu.setString("Jugar otra vez (space)");
	menu.setPosition(sf::Vector2f(540 / 2, 480 / (MAX_NUMBER_OF_ITEMS + 1) * 1));
	m_window.dibujar(menu);

	m_window.desplegar();
	while (!eleccion) {
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::R)) {
			for (int i = 0; i < 3; i++) {
				for (int j = 0; j < 3; j++) {
					mapa[i][j] = "";
				}
			}
			eleccion = true;
			q = 0; w = 0; e = 0; a = 0; s = 0; d = 0; z = 0; x = 0; c = 0;
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
	Q();
	W();
	E();
	A();
	S();
	D();
	Z();
	X();
	C();
}

void Partida::manejarEntrada() {
	
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Q)) {
		if (turnoPJ1 && mapa[0][0] != "O") {
			mapa[0][0] = "X";
			q = 1;
			turnoPJ1 = false;
			return;
		}
		else if (!turnoPJ1 && mapa[0][0] != "X") {
			mapa[0][0] = "O";
			q = 2;
			turnoPJ1 = true;
			return;
		}
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) {
		if (turnoPJ1 && mapa[0][1] != "O") {
			mapa[0][1] = "X";
			w = 1;
			turnoPJ1 = false;
			return;
		}
		else if (!turnoPJ1 && mapa[0][1] != "X") {
			mapa[0][1] = "O";
			w = 2;
			turnoPJ1 = true;
			return;
		}
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::E)) {
		if (turnoPJ1 && mapa[0][2] != "O") {
			mapa[0][2] = "X";
			e = 1;
			turnoPJ1 = false;
			return;
		}
		else if (!turnoPJ1 && mapa[0][2] != "X") {
			mapa[0][2] = "O";
			e = 2;
			turnoPJ1 = true;
			return;
		}
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
		if (turnoPJ1 && mapa[1][0] != "O") {
			mapa[1][0] = "X";
			a = 1;
			turnoPJ1 = false;
			return;
		}
		else if (!turnoPJ1 && mapa[1][0] != "X") {
			mapa[1][0] = "O";
			a = 2;
			turnoPJ1 = true;
			return;
		}
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {
		if (turnoPJ1 && mapa[1][1] != "O") {
			mapa[1][1] = "X";
			s = 1;
			turnoPJ1 = false;
			return;
		}
		else if (!turnoPJ1 && mapa[1][1] != "X") {
			mapa[1][1] = "O";
			s = 2;
			turnoPJ1 = true;
			return;
		}
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
		if (turnoPJ1 && mapa[1][2] != "O") {
			mapa[1][2] = "X";
			d = 1;
			turnoPJ1 = false;
			return;
		}
		else if (!turnoPJ1 && mapa[1][2] != "X") {
			mapa[1][2] = "O";
			d = 2;
			turnoPJ1 = true;
			return;
		}
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Z)) {
		if (turnoPJ1 && mapa[2][0] != "O") {
			mapa[2][0] = "X";
			z = 1;
			turnoPJ1 = false;
			return;
		}
		else if (!turnoPJ1 && mapa[2][0] != "X") {
			mapa[2][0] = "O";
			z = 2;
			turnoPJ1 = true;
			return;
		}
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::X)) {
		if (turnoPJ1 && mapa[2][1] != "O") {
			mapa[2][1] = "X";
			x = 1;
			turnoPJ1 = false;
			return;
		}
		else if (!turnoPJ1 && mapa[2][1] != "X") {
			mapa[2][1] = "O";
			x = 2;
			turnoPJ1 = true;
			return;
		}
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::C)) {
		if (turnoPJ1 && mapa[2][2] != "O") {
			mapa[2][2] = "X";
			c = 1;
			turnoPJ1 = false;
			return;
		}
		else if (!turnoPJ1 && mapa[2][2] != "X") {
			mapa[2][2] = "O";
			c = 2;
			turnoPJ1 = true;
			return;
		}
	}
}

bool Partida::nivelCompleto()
{
	if (mapa[0][0] == "X" && mapa[0][1] == "X" && mapa[0][2] == "X")
	{
		cout << "EL jugador 1 gana" << endl;
		return false;
	}
	else if (mapa[1][0] == "X" && mapa[1][1] == "X" && mapa[1][2] == "X")
	{
		cout << "EL jugador 1 gana" << endl;
		return false;
	}
	else if (mapa[2][0] == "X" && mapa[2][1] == "X" && mapa[2][2] == "X")
	{
		cout << "EL jugador 1 gana" << endl;
		return false;
	}
	//columnas
	else if (mapa[0][0] == "X" && mapa[1][0] == "X" && mapa[2][0] == "X")
	{
		cout << "EL jugador 1 gana" << endl;
		return false;
	}
	else if (mapa[0][1] == "X" && mapa[1][1] == "X" && mapa[2][1] == "X")
	{
		cout << "EL jugador 1 gana" << endl;
		return false;
	}
	else if (mapa[0][2] == "X" && mapa[1][2] == "X" && mapa[2][2] == "X")
	{
		cout << "EL jugador 1 gana" << endl;
		return false;
	}
	//vertical
	else if (mapa[0][0] == "X" && mapa[1][1] == "X" && mapa[2][2] == "X")
	{
		cout << "EL jugador 1 gana" << endl;
		return false;
	}
	else if (mapa[0][2] == "X" && mapa[1][1] == "X" && mapa[2][0] == "X")
	{
		cout << "EL jugador 1 gana" << endl;
		return false;
	}
	//segundo
	if (mapa[0][0] == "O" && mapa[0][1] == "O" && mapa[0][2] == "O")
	{
		cout << "EL jugador 2 gana" << endl;
		return false;
	}
	else if (mapa[1][0] == "O" && mapa[1][1] == "O" && mapa[1][2] == "O")
	{
		cout << "EL jugador 2 gana" << endl;
		return false;
	}
	else if (mapa[2][0] == "O" && mapa[2][1] == "O" && mapa[2][2] == "O")
	{
		cout << "EL jugador 2 gana" << endl;
		return false;
	}
	//columnas
	else if (mapa[0][0] == "O" && mapa[1][0] == "O" && mapa[2][0] == "O")
	{
		cout << "EL jugador 2 gana" << endl;
		return false;
	}
	else if (mapa[0][1] == "O" && mapa[1][1] == "O" && mapa[2][1] == "O")
	{
		cout << "EL jugador 2 gana" << endl;
		return false;
	}
	else if (mapa[0][2] == "O" && mapa[1][2] == "O" && mapa[2][2] == "O")
	{
		cout << "EL jugador 2 gana" << endl;
		return false;
	}
	//vertical
	else if (mapa[0][0] == "O" && mapa[1][1] == "O" && mapa[2][2] == "O")
	{
		cout << "EL jugador 2 gana" << endl;
		return false;
	}
	else if (mapa[0][2] == "O" && mapa[1][1] == "O" && mapa[2][0] == "O")
	{
		cout << "EL jugador 2 gana" << endl;
		return false;
	}
	else
		return true;
}

void Partida::Q() {
	sprite.setPosition(30, 0);
	if (q == 1) {
		sprite.setTexture(texturaX);
		m_window.dibujar(sprite);
	}
	else if(q == 2) {
		sprite.setTexture(texturaO);
		m_window.dibujar(sprite);
	}
}
void Partida::W() {
	sprite.setPosition(300, 0);
	if (w == 1) {
		sprite.setTexture(texturaX);
		m_window.dibujar(sprite);
	}
	else if (w == 2) {
		sprite.setTexture(texturaO);
		m_window.dibujar(sprite);
	}
}
void Partida::E() {
	sprite.setPosition(560, 0);
	if (e == 1) {
		sprite.setTexture(texturaX);
		m_window.dibujar(sprite);
	}
	else if (e == 2) {
		sprite.setTexture(texturaO);
		m_window.dibujar(sprite);
	}
}
void Partida::A() {
	sprite.setPosition(30, 200);
	if (a == 1) {
		sprite.setTexture(texturaX);
		m_window.dibujar(sprite);
	}
	else if (a == 2) {
		sprite.setTexture(texturaO);
		m_window.dibujar(sprite);
	}
}
void Partida::S() {
	sprite.setPosition(300, 200);
	if (s == 1) {
		sprite.setTexture(texturaX);
		m_window.dibujar(sprite);
	}
	else if (s == 2) {
		sprite.setTexture(texturaO);
		m_window.dibujar(sprite);
	}
}
void Partida::D() {
	sprite.setPosition(560, 200);
	if (d == 1) {
		sprite.setTexture(texturaX);
		m_window.dibujar(sprite);
	}
	else if (d == 2) {
		sprite.setTexture(texturaO);
		m_window.dibujar(sprite);
	}
}
void Partida::Z() {
	sprite.setPosition(30, 400);
	if (z == 1) {
		sprite.setTexture(texturaX);
		m_window.dibujar(sprite);
	}
	else if (z == 2) {
		sprite.setTexture(texturaO);
		m_window.dibujar(sprite);
	}
}
void Partida::X() {
	sprite.setPosition(300, 400);
	if (x == 1) {
		sprite.setTexture(texturaX);
		m_window.dibujar(sprite);
	}
	else if (x == 2) {
		sprite.setTexture(texturaO);
		m_window.dibujar(sprite);
	}
}
void Partida::C() {
	sprite.setPosition(560, 400);
	if (c == 1) {
		sprite.setTexture(texturaX);
		m_window.dibujar(sprite);
	}
	else if (c == 2) {
		sprite.setTexture(texturaO);
		m_window.dibujar(sprite);
	}
}