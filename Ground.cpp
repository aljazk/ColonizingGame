#include "Ground.h"

std::shared_ptr<GroundVertex> Ground::getTopVertex(const int x, const int y)
{
	if (y < 1) {
		return nullptr;
	}
	else {
		GroundTile* topTile = groundTiles[x][y - 1];
		int vertexNumber = 0;
		if (y % 2 == 1) {
			vertexNumber = 2;
		}
		return topTile->getHeightVertex(vertexNumber);
	}
}

std::shared_ptr<GroundVertex> Ground::getLeftVertex(const int x, const int y)
{
	if (y % 2 == 0) {
		if (x < 1) {
			return nullptr;
		}
		else {
			GroundTile* leftTile = leftTile = groundTiles[x - 1][y];
			return leftTile->getHeightVertex(2);
		}
	}
	else {
		if (y < 1) {
			return nullptr;
		}
		else {
			GroundTile* leftTile = leftTile = groundTiles[x][y - 1];
			return leftTile->getHeightVertex(3);
		}
	}
}

std::shared_ptr<GroundVertex> Ground::getRightVertex(const int x, const int y)
{
	if (y % 2 == 0) {
		if (y < 1) {
			return nullptr;
		}
		else {
			GroundTile* rightTile = rightTile = groundTiles[x][y - 1];
			return rightTile->getHeightVertex(3);
		}
	}
	else {
		return nullptr;
	}
}

std::shared_ptr<GroundVertex> Ground::getBottomVertex(const int x, const int y)
{
	if (y % 2 == 0) {
		if (y >= (int)size.y-1 || x < 1) {
			return nullptr;
		}
		else {
			GroundTile* rightTile = rightTile = groundTiles[x - 1][y + 1];
			return rightTile->getHeightVertex(2);
		}
	}
	else {
		return nullptr;
	}
}

Ground::Ground()
{
	size = sf::Vector2u(20, 40);
	groundTiles = new GroundTile ** [size.x];
	for (unsigned int x = 0; x < size.x; x++) {
		groundTiles[x] = new GroundTile*[size.y];
		for (unsigned int y = 0; y < size.y; y++) {
			std::shared_ptr<GroundVertex> topVertex = getTopVertex(x, y);
			if (topVertex == nullptr) {
				topVertex = std::make_shared<GroundVertex>(0);
			}
			std::shared_ptr<GroundVertex> leftVertex = getLeftVertex(x, y);
			if (leftVertex == nullptr) {
				leftVertex = std::make_shared<GroundVertex>(0);
			}
			std::shared_ptr<GroundVertex> rightVertex = getRightVertex(x, y);
			if (rightVertex == nullptr) {
				rightVertex = std::make_shared<GroundVertex>(0);
			}
			std::shared_ptr<GroundVertex> bottomVertex = getBottomVertex(x, y);
			if (bottomVertex == nullptr) {
				bottomVertex = std::make_shared<GroundVertex>(0);
			}
			if (x == 5 && y == 5) {
				groundTiles[x][y] = new GroundTile(sf::Vector2u(x, y), leftVertex, topVertex, rightVertex, std::make_shared<GroundVertex>(1));
			}
			else {
				groundTiles[x][y] = new GroundTile(sf::Vector2u(x, y), leftVertex, topVertex, rightVertex, bottomVertex);
			}
		}
	}
}

Ground::~Ground()
{
	std::cout << "Deleting ground. " << std::endl;
	for (unsigned int x = 0; x < size.x; x++) {
		for (unsigned int y = 0; y < size.y; y++) {
			delete groundTiles[x][y];
		}
		delete[] groundTiles[x];
	}
	delete[] groundTiles;
	std::cout << "Ground deleted" << std::endl;
}

void Ground::Add(GroundTile* tile)
{
	//groundTiles.push_back(tile);
}

void Ground::AppendToVertexArray(sf::VertexArray& vertexArray)
{
	for (unsigned int x = 0; x < size.x; x++) {
		for (unsigned int y = 0; y < size.y; y++) {
			groundTiles[x][y]->AppendToVertexArray(vertexArray);
		}
	}
}
