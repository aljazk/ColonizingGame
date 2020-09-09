#pragma once
#include "GroundTile.h"
#include "GroundVertex.h"
#include <vector>
#include <memory>

class Ground : Entity
{
private:
	sf::Vector2u size;
	 GroundTile*** groundTiles;
	 std::shared_ptr<GroundVertex> getTopVertex(const int x, const int y);
	 std::shared_ptr<GroundVertex> getLeftVertex(const int x, const int y);
	 std::shared_ptr<GroundVertex> getRightVertex(const int x, const int y);
	 std::shared_ptr<GroundVertex> getBottomVertex(const int x, const int y);
public:
	Ground();
	~Ground();
	void Add(GroundTile *tile);
	void AppendToVertexArray(sf::VertexArray &vertexArray);
};

