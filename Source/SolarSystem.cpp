#include "SolarSystem.hpp"

#include "Settings.hpp"

#include <SFML/Graphics/CircleShape.hpp>

#include <cmath>

namespace SpaceSim
{
    void SolarSystem::AddBody(Body body)
    {
        m_Bodies.emplace_back(std::move(body));
    }

    void SolarSystem::Update(double dt)
    {
        m_Time += dt;

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
            if (ToScaleBodies)
            {
                circle.setRadius(static_cast<float>(body.Radius * PixelPerM));
            }

            circle.setFillColor(body.Color);
            circle.setPosition(ToCoords(body.Position));

            window.draw(circle);
        }
    }

    double SolarSystem::AgeInYears() const
    {
        return m_Time / (60.0 * 60.0 * 24.0 * 365.25);
    }

    std::vector<Body> &SolarSystem::GetBodies()
    {
        return m_Bodies;
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