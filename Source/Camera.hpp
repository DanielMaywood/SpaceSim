#pragma once

#include "Position.hpp"

#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics/View.hpp>
#include <SFML/Window/Event.hpp>

namespace SpaceSim
{
    class Camera
    {
    public:
        explicit Camera(sf::RenderWindow &window, sf::View &view);

        void GoToPosition(const Position &position);
        void TrackPosition(const Position *position);

        void Update();

        void OnEvent(const sf::Event &event);

    private:
        void OnMouseWheelMoved(const sf::Event &event);
        void OnMouseButtonPressed(const sf::Event &event);
        void OnMouseButtonLeftPressed(const sf::Event &event);
        void OnMouseButtonReleased(const sf::Event &event);
        void OnMouseButtonLeftReleased(const sf::Event &event);
        void OnMouseMoved(const sf::Event &event);

    private:
        sf::RenderWindow &m_Window;
        sf::View &        m_View;

        const Position *m_TrackingPosition = nullptr;

        sf::Vector2i m_MovingCameraLastPosition;
        bool         m_MovingCamera = false;
    };
} // namespace SpaceSim