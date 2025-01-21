#include <SFML/Graphics.hpp>
#include "Button.hpp"
#include <iostream>

int main()
{
    // Initialize window
    auto window = sf::RenderWindow(sf::VideoMode({800u, 800u}), "sfml-tests");
    window.setFramerateLimit(60);
    
    const auto onClose = [&window](const sf::Event::Closed&)
    {
        window.close();
    };

    const auto onKeyPressed = [&window](const sf::Event::KeyPressed& keyPressed)
    {
        if (keyPressed.scancode == sf::Keyboard::Scancode::Escape)
            window.close();
        else
            std::cout << "Key pressed! Code: " << static_cast<int>(keyPressed.code) << ", Scancode: " << static_cast<int>(keyPressed.scancode) << std::endl;
    };
    
    const auto onMouseClicked = [&window](const sf::Event::MouseButtonPressed& mouseClicked)
    {
        if (mouseClicked.button == sf::Mouse::Button::Left)
        {
            std::cout << "Left mouse button pressed at (" << mouseClicked.position.x << ", " << mouseClicked.position.y << ")" << std::endl;
        }

        else if (mouseClicked.button == sf::Mouse::Button::Right)
        {
            std::cout << "Right mouse button pressed at (" << mouseClicked.position.x << ", " << mouseClicked.position.y << ")" << std::endl;
        }
    };

    while (window.isOpen())
    {
        window.handleEvents(onClose, onKeyPressed, onMouseClicked);
        
        window.clear(sf::Color(50, 50, 50));

        window.display();
    }
}