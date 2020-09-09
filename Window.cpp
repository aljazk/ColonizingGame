
#include "Window.h"
#include <iostream>
#include <SFML/Window.hpp>
#include "Rectangle.h"
#include "Noise.h"

void Window::displayFps(sf::RenderWindow& window)
{
    fps = 100 / clock.restart().asSeconds();
    fps = (int)fps / 100.0f;
    std::ostringstream fpsString;
    fpsString << fps << " fps";
    fpsText.setString(fpsString.str());
    window.draw(fpsText);
}

Window::Window()
{
    fps = 0;
    window.create(sf::VideoMode(1200, 900), "Colonization game");
    //window.setFramerateLimit(60);
    if (!font.loadFromFile("arial.ttf")) {
        std::cout << "Cannot load font." << std::endl;
    } else {
        fpsText.setFont(font);
        fpsText.setPosition(5, 5);
        fpsText.setCharacterSize(12);
    }
}

void Window::Run()
{
    sf::VertexArray vertexArray(sf::Triangles);
    /*
    sf::Vertex vertex;
    Noise noise(256, 256);
    //noise.printArray();
    std::cout << "Setting vertices. ";
    int tile_size = 50;
    for (unsigned int i = 0; i < window.getSize().x/tile_size; i++) {
        for (unsigned int j = 0; j < window.getSize().y/tile_size; j++) {
            float pos = noise.perlin(i * 0.06f, j * 0.06f) * 255/2 + 255/2;
            vertex.color = sf::Color((sf::Uint8)pos, (sf::Uint8)pos, (sf::Uint8)pos, 255);
            vertex.position = sf::Vector2f((float)i * tile_size, (float)j * tile_size);
            vertexArray.append(vertex);
            vertex.position = sf::Vector2f((float)(i+1) * tile_size, (float)j * tile_size);
            vertexArray.append(vertex);
            vertex.position = sf::Vector2f((float)(i+1) * tile_size, (float)(j+1) * tile_size);
            vertexArray.append(vertex);
            vertex.position = sf::Vector2f((float)i * tile_size, (float)j * tile_size);
            vertexArray.append(vertex);
            vertex.position = sf::Vector2f((float)i * tile_size, (float)(j+1) * tile_size);
            vertexArray.append(vertex);
            vertex.position = sf::Vector2f((float)(i + 1) * tile_size, (float)(j + 1) * tile_size);
            vertexArray.append(vertex);
        }
    }
    std::cout << "Done." << std::endl;

    */
    Ground ground;
    ground.AppendToVertexArray(vertexArray);

    // run the program as long as the window is open
    while (window.isOpen())
    {
        // check all the window's events that were triggered since the last iteration of the loop
        sf::Event event;
        while (window.pollEvent(event))
        {
            // "close requested" event: we close the window
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear();
        window.draw(vertexArray);

        displayFps(window);
        window.display();
    }
}
