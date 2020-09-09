#pragma once
#include <SFML/Window.hpp>
#include <sstream>
#include "Rectangle.h"
#include "Ground.h"

class Window
{
private:
	sf::RenderWindow window;
	float fps;
	sf::Clock clock;
	sf::Time elapsed;
	sf::Font font;
	sf::Text fpsText;
	void displayFps(sf::RenderWindow& window);
public:
	Window();
	void Run();
};

