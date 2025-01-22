#include <SFML/Graphics.hpp>
#include <imgui.h>
#include <imgui-SFML.h>

#include <iostream>

struct imGuiWindow {
    bool open = true;
    std::string name = "Hello, world!";
    std::string buttonName = "Look at this pretty button";
};



int main() {
    sf::RenderWindow window(sf::VideoMode({640, 480}), "ImGui + SFML = <3");
    window.setFramerateLimit(60);
    // TODO: learn more about this warning
    ImGui::SFML::Init(window);

    sf::Clock deltaClock;
    
    bool windowAOpen = true, 
         windowBOpen = true;

    int mainMenuButtonHeight = 50;

    /****************************
     **       GAME LOOP        **
     ****************************/
    while (window.isOpen()) {

        // Event handling
        while (const auto event = window.pollEvent()) {
            ImGui::SFML::ProcessEvent(window, *event);

            if (event->is<sf::Event::Closed>()) {
                window.close();
            }
        }


        ImGui::SFML::Update(window, deltaClock.restart());

        if(windowAOpen) {
            ImGui::SetNextWindowSize({200, 300});
            ImGui::SetNextWindowPos({0, 0});
            ImGui::Begin("Hello, world!", nullptr, 
                ImGuiWindowFlags_NoResize   | 
                ImGuiWindowFlags_NoMove     | 
                ImGuiWindowFlags_NoCollapse |
                ImGuiWindowFlags_NoTitleBar );
            ImGui::Button("START", { static_cast<int>(ImGui::GetContentRegionAvail()[0]), mainMenuButtonHeight });
            ImGui::Button("EXIT",  { static_cast<int>(ImGui::GetContentRegionAvail()[0]), mainMenuButtonHeight });
            ImGui::End();
        }

        window.clear();
        ImGui::SFML::Render(window);
        window.display();
    }

    ImGui::SFML::Shutdown();
}