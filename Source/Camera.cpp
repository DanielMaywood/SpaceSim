#include "Camera.hpp"

#include <iostream>

namespace SpaceSim
{
    Camera::Camera(sf::RenderWindow &window, sf::View &view)
        : m_Window(window)
        , m_View(view)
    {
    }

    void Camera::OnEvent(const sf::Event &event)
    {
        switch (event.type)
        {
        case sf::Event::MouseWheelMoved: OnMouseWheelMoved(event); break;
        case sf::Event::MouseButtonPressed: OnMouseButtonPressed(event); break;
        case sf::Event::MouseButtonReleased: OnMouseButtonReleased(event); break;
        case sf::Event::MouseMoved: OnMouseMoved(event); break;
        }
    }

    void Camera::OnMouseWheelMoved(const sf::Event &event)
    {
        m_View.zoom(event.mouseWheel.delta * -0.05f + 1.f);

        m_Window.setView(m_View);
    }

    void Camera::OnMouseButtonPressed(const sf::Event &event)
    {
        switch (event.mouseButton.button)
        {
        case sf::Mouse::Left: OnMouseButtonLeftPressed(event); break;
        }
    }

    void Camera::OnMouseButtonLeftPressed(const sf::Event &event)
    {
        m_MovingCameraLastPosition = {event.mouseButton.x, event.mouseButton.y};
        m_MovingCamera             = true;
    }

    void Camera::OnMouseButtonReleased(const sf::Event &event)
    {
        switch (event.mouseButton.button)
        {
        case sf::Mouse::Left: OnMouseButtonLeftReleased(event); break;
        }
    }

    void Camera::OnMouseButtonLeftReleased(const sf::Event &event)
    {
        m_MovingCamera = false;
    }

    void Camera::OnMouseMoved(const sf::Event &event)
    {
        if (!m_MovingCamera)
        {
            return;
        }

        sf::Vector2 newPosition = {event.mouseMove.x, event.mouseMove.y};
        sf::Vector2 change      = m_MovingCameraLastPosition - newPosition;
        sf::Vector2 center      = m_Window.mapCoordsToPixel(m_View.getCenter(), m_View);

        m_View.setCenter(m_Window.mapPixelToCoords(center + change));
        m_Window.setView(m_View);

        m_MovingCameraLastPosition = newPosition;
    }
} // namespace SpaceSim