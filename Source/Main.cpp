#include "Application.hpp"

#include <SFML/Graphics.hpp>

int main()
{
    using namespace SpaceSim;
    using namespace sf;

    RenderWindow window(sf::VideoMode(1280, 720), "SpaceSim");
    Application  application(window);

    application.OnSetup();

    Clock deltaClock;

    while (window.isOpen())
    {
        window.clear(sf::Color::Black);
        application.OnFrame(deltaClock.restart());
        window.display();
    }
}