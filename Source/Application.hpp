#pragma once

#include "SolarSystem.hpp"

#include <SFML/Graphics.hpp>

namespace SpaceSim
{
    class Application
    {
    public:
        explicit Application(sf::RenderWindow &window);

        void OnSetup();
        void OnFrame(sf::Time dt);

    private:
        void DrawImGuiLayer();
        void DrawImGuiLayer_Settings();

        void CloseWindow();
        void ZoomInWindow(const sf::Event &event);

    private:
        sf::RenderWindow &m_Window;
        sf::View          m_View;
        SolarSystem       m_SolarSystem;
        bool              m_SimulationActive;
    };
} // namespace SpaceSim