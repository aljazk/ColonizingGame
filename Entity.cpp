#include "Entity.h"

Entity::Entity()
{
	rotation = 0;
}

void Entity::AppendToVertexArray(const sf::VertexArray& vertexArray)
{

}

void Entity::setPosition(float x, float y) {
	this->position.x = x;
	this->position.y = y;
}

void Entity::setPosition(sf::Vector2f pos) {
	this->position = pos;
}

void Entity::setSize(float height, float width) {
	this->size.x = height;
	this->size.y = width;
}

void Entity::setSize(sf::Vector2f size) {
	this->size = size;
}

void Entity::setConterOfMass(float x, float y) {
	this->centerOfMass.x = x;
	this->centerOfMass.y = y;
}

void Entity::setCenterOfMass(sf::Vector2f center) {
	this->centerOfMass = center;
}

void Entity::setRotatino(float rotatino) {
	this->rotation = rotatino;
}

sf::Vector2f Entity::getPosition()
{
	return this->position;
}
sf::Vector2f Entity::getSize()
{
	return this->size;
}
sf::Vector2f Entity::getCenterOfMass()
{
	return this->centerOfMass;
}

float Entity::getRotation() {
	return this->rotation;
}
