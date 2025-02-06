#include <SFML/Graphics.hpp>
#include <iostream>
#include "GameLoop.h"

int main()
{
    float frameRate = 144.f;

    auto window = sf::RenderWindow(sf::VideoMode({ 1280u, 720u }), "CMake SFML Project");
    window.setFramerateLimit(frameRate);

    GameLoop gameLoop;

    sf::Event event = sf::Event();

    gameLoop.Start();

    while (window.isOpen())
    {
        while (window.pollEvent(event))
        {            
            if (event.type == sf::Event::Closed)
            {
                window.close();                
            }
        }
        
        gameLoop.Update(10.f/ frameRate);

        window.clear();
        gameLoop.Render(window);
        window.display();
    }

    std::cout << "close";

    return 0;
}