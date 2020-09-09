#include "GroundTile.h"
#include "GroundVertex.h"

const float GroundTile::angle = 0.6f;

sf::Vector2f GroundTile::getCenter()
{
	int move_left = position.y % 2;
	int size = tile_size + margin;
	return sf::Vector2f((float)position.x * size + size /2 * move_left, (float)position.y * angle * size /2);
}

GroundTile::GroundTile(sf::Vector2u position, std::shared_ptr<GroundVertex> h0, std::shared_ptr<GroundVertex> h1, std::shared_ptr<GroundVertex> h2, std::shared_ptr<GroundVertex> h3)
{
	this->position = position;
	heights.push_back(h0);
	heights.push_back(h1);
	heights.push_back(h2);
	heights.push_back(h3);
}

void GroundTile::AppendToVertexArray(sf::VertexArray& vertexArray)
{
    sf::Vertex vertex;
    vertex.color = sf::Color(100, 200, 50, 255);
	if (position.x == 5 && position.y == 5) {
		vertex.color.r = 255;
	}
	sf::Vector2f center = getCenter();
	float width = 1.0 * tile_size / 2;
	float height = angle * tile_size / 2;
	vertex.position = sf::Vector2f(center.x - width, center.y - heights[0]->getHeight() * elevationHeight);
	vertexArray.append(vertex);
	vertex.position = sf::Vector2f(center.x, center.y - height - heights[1]->getHeight() * elevationHeight);
	vertexArray.append(vertex);
	vertex.position = sf::Vector2f(center.x + width, center.y - heights[2]->getHeight() * elevationHeight);
	vertexArray.append(vertex);
	vertex.position = sf::Vector2f(center.x - width, center.y - heights[0]->getHeight() * elevationHeight);
	vertexArray.append(vertex);
	vertex.position = sf::Vector2f(center.x, center.y + height - heights[3]->getHeight() * elevationHeight);
	vertexArray.append(vertex);
	vertex.position = sf::Vector2f(center.x + width, center.y - heights[2]->getHeight() * elevationHeight);
	vertexArray.append(vertex);
}

std::shared_ptr<GroundVertex> GroundTile::getHeightVertex(int id)
{
	if (id < 0) {
		return nullptr;
	}
	else if (id > 3) {
		return nullptr;
	}
	else {
		return heights[id];
	}
}
