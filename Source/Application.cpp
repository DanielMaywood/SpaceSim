#include "Application.hpp"

#include "Settings.hpp"

#include <iostream>

namespace SpaceSim
{
    Application::Application(sf::RenderWindow &window)
        : m_Window(window)
        , m_View(window.getDefaultView())
    {
        const sf::Vector2 windowSize = window.getSize();

        m_View.setSize(static_cast<float>(windowSize.x), static_cast<float>(windowSize.y));
        m_View.setCenter(0.f, 0.f);

        m_Window.setView(m_View);
    }

    void Application::OnSetup()
    {
        m_SolarSystem.AddBody(Body::Sun());
        m_SolarSystem.AddBody(Body::Earth());
        m_SolarSystem.AddBody(Body::Mars());
    }

    void Application::OnFrame(double dt)
    {
        m_SolarSystem.Update(dt * TimeScale);
        m_SolarSystem.Draw(m_Window);

        for (sf::Event event; m_Window.pollEvent(event);)
        {
            switch (event.type)
            {
            case sf::Event::Closed: CloseWindow(); break;
            case sf::Event::MouseWheelMoved: ZoomInWindow(event); break;
            }
        }
    }

    void Application::CloseWindow()
    {
        m_Window.close();
    }

    void Application::ZoomInWindow(const sf::Event &event)
    {
        m_View.zoom(event.mouseWheel.delta * -0.05f + 1.f);

        m_Window.setView(m_View);
    }
} // namespace SpaceSim