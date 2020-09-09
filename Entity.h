#pragma once
#include <SFML/Graphics.hpp>

class Entity {
private:
	sf::Vector2f position;
	sf::Vector2f size;
	sf::Vector2f centerOfMass;
	float rotation;
public:
	Entity();

	virtual void AppendToVertexArray(const sf::VertexArray& vertexArray);

	void setPosition(float x, float y);

	void setPosition(sf::Vector2f pos);

	void setSize(float height, float width);

	void setSize(sf::Vector2f size);

	void setConterOfMass(float x, float y);

	void setCenterOfMass(sf::Vector2f center);

	void setRotatino(float rotatino);

	sf::Vector2f getPosition();

	sf::Vector2f getSize();

	sf::Vector2f getCenterOfMass();

	float getRotation();

};

