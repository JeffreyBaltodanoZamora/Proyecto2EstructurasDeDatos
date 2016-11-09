#pragma once

#include <Windows.h>
#include <fstream>
#include <vector>
#include <iostream>
#include "window.h"
#include "menu.h"

using namespace std;

struct nodo
{
	nodo* anterior;
	nodo* siguiente;
	int estado;
};

class Partida
{
public:
	Partida();
	~Partida();
	void nuevaPartidaJvJ();
	void agregaTexturasEscenario(Window &window);
	void manejarEntrada();
	bool nivelCompleto();
	int subMenuNivel();
	void Q();
	void W();
	void E();
	void A();
	void S();
	void D();
	void Z();
	void X();
	void C();
private:
	int q,w,e,a,s,d,z,x,c;
	bool turnoPJ1 = true;
	string mapa[3][3];
	sf::Sprite sprite;
	Window m_window;
	sf::Font font;
	sf::Text menu;
	sf::Texture texturaFondo;
	sf::Texture texturaX;
	sf::Texture texturaO;
};