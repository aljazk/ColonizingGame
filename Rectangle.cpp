#include "Rectangle.h"

void Rectangle::AppendToVertexArray(sf::VertexArray& vertexArray)
{
	sf::Vertex vertex;
	vertex.position = sf::Vector2f(this->getPosition().x - this->getSize().x / 2.0f, this->getPosition().y - this->getSize().y / 2.0f);
	vertexArray.append(vertex);
	vertex.position = sf::Vector2f(this->getPosition().x + this->getSize().x / 2.0f, this->getPosition().y - this->getSize().y / 2.0f);
	vertexArray.append(vertex);
	vertex.position = sf::Vector2f(this->getPosition().x + this->getSize().x / 2.0f, this->getPosition().y + this->getSize().y / 2.0f);
	vertexArray.append(vertex);
	vertex.position = sf::Vector2f(this->getPosition().x - this->getSize().x / 2.0f, this->getPosition().y + this->getSize().y / 2.0f);
	vertexArray.append(vertex);
}
