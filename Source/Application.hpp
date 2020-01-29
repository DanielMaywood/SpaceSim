#pragma once

#include "Camera.hpp"
#include "SolarSystem.hpp"

#include "Camera.hpp"
#include "Spawner.hpp"

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
        /// <summary>
        /// Processes SolarSystem's Update and Draw.
        /// </summary>
        void ProcessSolarSystemOnFrame(sf::Time dt);

        /// <summary>
        /// Process Camera's Update.
        /// </summary>
        void ProcessCameraOnFrame();

        /// <summary>
        /// Process Spawner's Draw.
        /// </summary>
        void ProcessSpawnerOnFrame();

        /// <summary>
        /// Process ImGui's Drawing.
        /// </summary>
        void ProcessImGuiOnFrame(sf::Time dt);

        /// <summary>
        /// Process Events.
        /// </summary>
        void ProcessEvents();

        /// <summary>
        /// Process Events.
        /// </summary>
        void ProcessImGuiOnEvent(const sf::Event &event);

        /// <summary>
        /// Process Events.
        /// </summary>
        void ProcessCameraOnEvent(const sf::Event &event);

        void DrawImGuiLayer();
        void DrawImGuiLayer_Settings();
        void DrawImGuiLayer_Bodies();
        void DrawImGuiLayer_Spawner();

        /// <summary>
        /// Set the Window to draw (0,0) in the middle
        /// of the screen with (0,1) beind above the
        /// center, with (0,-1) being below. Instead
        /// of the default behaviour.
        /// </summary>
        void FixWindowView();

    private:
        sf::RenderWindow &m_Window;
        sf::View          m_View;
        Camera            m_Camera;
        Spawner           m_Spawner;
        SolarSystem       m_SolarSystem;
        bool              m_SimulationActive;
    };
} // namespace SpaceSim