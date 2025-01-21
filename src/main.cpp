#include <SFML/Graphics.hpp>
#include "Button.hpp"
#include <iostream>

int main()
{
    auto window = sf::RenderWindow(sf::VideoMode({800u, 800u}), "sfml-tests");
    window.setFramerateLimit(144);
    
    const auto onClose = [&window](const sf::Event::Closed&)
    {
        window.close();
    };

    const auto onKeyPressed = [&window](const sf::Event::KeyPressed& keyPressed)
    {
        if (keyPressed.scancode == sf::Keyboard::Scancode::Escape)
            window.close();
    };

    while (window.isOpen())
    {
        window.handleEvents(onClose, onKeyPressed);

        window.clear(sf::Color(50, 50, 50));

        window.display();
    }
}