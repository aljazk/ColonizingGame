#include "GroundVertex.h"
#include "GroundTile.h"

void GroundVertex::updateTiles()
{
	for (GroundTile* groundTile : connectingTiles) {
		
	}
}

GroundVertex::GroundVertex(int height)
{
	setHeight(height);
}

void GroundVertex::AddTile(GroundTile* groundTile)
{
	connectingTiles.push_back(groundTile);
}

int GroundVertex::getHeight()
{
	return height;
}

void GroundVertex::setHeight(int height)
{
	this->height = height;
	updateTiles();
}

void GroundVertex::rise()
{
	setHeight(height++);
}

void GroundVertex::lower()
{
	setHeight(height--);
}
