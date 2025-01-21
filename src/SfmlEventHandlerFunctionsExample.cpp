#include <SFML/Graphics.hpp>
#include <imgui.h>
#include <imgui-SFML.h>

#include <iostream>

int main()
{
    // Initialize window
    auto window = sf::RenderWindow(sf::VideoMode({800u, 800u}), "sfml-tests");
    window.setFramerateLimit(60);
    ImGui::SFML::Init(window);

    sf::Clock deltaClock;
    
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

        ImGui::SFML::ProcessEvent(window, keyPressed);
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

        ImGui::SFML::ProcessEvent(window, mouseClicked);
    };

    while (window.isOpen())
    {
        //window.handleEvents(onClose, onKeyPressed, onMouseClicked);
        while (const auto event = window.pollEvent()) {
            ImGui::SFML::ProcessEvent(window, *event);

            if (event->is<sf::Event::Closed>()) {
                window.close();
            }
        }
        
        ImGui::SFML::Update(window, deltaClock.restart());
        ImGui::ShowDemoWindow();

        window.clear(sf::Color(50, 50, 50));
        ImGui::SFML::Render(window);
        window.display();
    }
}