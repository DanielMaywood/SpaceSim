#include "SolarSystem.hpp"

#include "Settings.hpp"

#include <cmath>

namespace SpaceSim
{
    void SolarSystem::AddBody(Body body)
    {
        m_Bodies.emplace_back(std::move(body));
    }

    void SolarSystem::Update(double dt)
    {
        for (auto &body : m_Bodies)
        {
            UpdateBody(body, dt);
        }
    }

    void SolarSystem::Draw(sf::RenderWindow &window) const
    {
        sf::CircleShape circle(3.f);

        for (const auto &body : m_Bodies)
        {
            const auto ToPixel = [&](double point) { return point * PixelPerM; };

            circle.setFillColor(body.Color);
            circle.setPosition(ToPixel(body.Position.X), ToPixel(body.Position.Y));

            window.draw(circle);
        }
    }

    void SolarSystem::UpdateBody(Body &body, double dt)
    {
        for (const auto &otherBody : m_Bodies)
        {
            if (std::addressof(body) == std::addressof(otherBody))
                continue;

            const double fieldStrength = GravitationalFieldStrength(body, otherBody);
            const double angleBetween  = AngleBetween(body, otherBody);

            body.Velocity.X -= fieldStrength * std::cos(angleBetween) * dt;
            body.Velocity.Y -= fieldStrength * std::sin(angleBetween) * dt;
        }

        body.Position += body.Velocity * dt;
    }
} // namespace SpaceSim