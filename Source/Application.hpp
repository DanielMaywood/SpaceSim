#pragma once

#include "Camera.hpp"
#include "SolarSystem.hpp"

#include "Spawner.hpp"
#include "Camera.hpp"

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
        void DrawImGuiLayer_Bodies();
        void DrawImGuiLayer_Spawner();

        void CloseWindow();

    private:
        sf::RenderWindow &m_Window;
        sf::View          m_View;
        Camera            m_Camera;
        Spawner           m_Spawner;
        SolarSystem       m_SolarSystem;
        bool              m_SimulationActive;
    };
} // namespace SpaceSim