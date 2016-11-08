// window.h
// Definición de la clase para la ventana

#ifndef WINDOW_H
#define WINDOW_H

#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <string>

class Window {
public:
	Window();
	Window(const std::string&, const sf::Vector2u&);
	~Window();

	sf::Vector2u getTamVentana();
	sf::RenderWindow* getWindow();
	void limpiar();
	void desplegar();
	void actualizar();
	void dibujar(sf::Drawable&);
	bool haTerminado();
	void destruir();
private:
	sf::RenderWindow m_window;
	sf::Vector2u m_windowTam;
	std::string m_windowTitulo;
	bool m_haTerminado;

	void configuracion(const std::string&, const sf::Vector2u&);
	void crear();

};

#endif