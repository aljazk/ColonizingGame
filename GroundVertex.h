#pragma once
#include <list>

class GroundTile;

class GroundVertex : Entity
{
private:
	std::list<GroundTile*> connectingTiles;
	int height;
	void updateTiles();
public:
	GroundVertex(int height);
	void AddTile(GroundTile* groundTile);
	int getHeight();
	void setHeight(int height);
	void rise();
	void lower();
};

