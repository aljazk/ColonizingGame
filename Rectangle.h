#pragma once
#include "Entity.h"

class Rectangle : public Entity
{
public:
	void AppendToVertexArray(sf::VertexArray& vertexArray);
};
