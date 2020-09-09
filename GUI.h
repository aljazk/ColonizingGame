#pragma once
#include <vector>
#include <memory>
#include <SFML/Graphics.hpp>
#include "GUIComponent.h"
class GUI
{
private:
	std::vector<std::unique_ptr<GUIComponent>> components;
public:
	void draw(sf::RenderWindow &window);
};

