#include <SFML/Graphics.hpp>

#include "Application.hpp"

#include <chrono>

int main()
{
    using namespace SpaceSim;
    using namespace std::chrono;
    using namespace sf;

    RenderWindow window(sf::VideoMode(1280, 720), "SpaceSim");
    Application  application(window);

    application.OnSetup();

    high_resolution_clock::time_point timer = high_resolution_clock::now();

    while (window.isOpen())
    {
        const auto time = high_resolution_clock::now();
        const auto dt   = duration<double>(time - timer).count();
        timer           = time;

        window.clear(sf::Color::Black);
        application.OnFrame(dt);
        window.display();
    }
}