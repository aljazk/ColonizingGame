#pragma once
#include <SFML/Graphics.hpp>
#include "Entity.h"
#include <iostream>
#include <vector>
#include <memory>

class GroundVertex;

class GroundTile : public Entity
{
private:
	static const int tile_size = 60;
	static const int margin = 5;
	static const int elevationHeight = 10;
	static const float angle;
	sf::Vector2u position;
	std::vector<std::shared_ptr<GroundVertex>> heights;
	sf::Vector2f getCenter();
public:
	GroundTile(sf::Vector2u position, std::shared_ptr<GroundVertex> h0, std::shared_ptr<GroundVertex> h1, std::shared_ptr<GroundVertex> h2, std::shared_ptr<GroundVertex> h3);
	void AppendToVertexArray(sf::VertexArray& vertexArray);
	std::shared_ptr<GroundVertex> getHeightVertex(int id);
};

