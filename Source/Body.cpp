#include "Body.hpp"

#include "Settings.hpp"

#include <SFML/Graphics/CircleShape.hpp>

namespace SpaceSim
{
    double DistanceBetween(const Body &body, const Body &other)
    {
        return DistanceBetween(body.Position, other.Position);
    }

    double AngleBetween(const Body &body, const Body &other)
    {
        return AngleBetween(body.Position, other.Position);
    }

    double GravitationalFieldStrength(const Body &body, const Body &other)
    {
        static constexpr const double GravitationalConstant = 6.67e-11;

        const double r = body.Radius + other.Radius + DistanceBetween(body, other);

        return (GravitationalConstant * other.Mass) / (r * r);
    }

    double CentripetalAcceleration(const Body &body, const Body &other)
    {
        const double velocity = std::sqrt(std::pow(body.Velocity.X, 2) + std::pow(body.Velocity.Y, 2));
        const double distance = body.Radius + other.Radius + DistanceBetween(body, other);

        return velocity / distance;
    }

    void Body::Draw(sf::RenderWindow &window) const
    {
        sf::CircleShape circle;

        circle.setRadius(ToScaleBodies ? static_cast<float>(Radius * PixelPerM) : 3.f);
        circle.setOrigin(ToScaleBodies ? ToCoords({Radius, Radius})
                                       : sf::Vector2 {circle.getRadius(), circle.getRadius()});
        circle.setFillColor(Color);
        circle.setPosition(ToCoords(Position));

        window.draw(circle);
    }

    Body Body::Sun()
    {
        return Body {
            .Name   = "Sun",
            .Mass   = 1.989e30,
            .Radius = 696'342'000,
            .Color  = sf::Color::Yellow,
        };
    }

    Body Body::Mercury()
    {
        return Body {
            .Name     = "Mercury",
            .Mass     = 3.285e23,
            .Radius   = 2'439'700,
            .Position = {53'397'000'000, 0},
            .Velocity = {0, 48'000},
            .Color    = sf::Color::White,
        };
    }

    Body Body::Venus()
    {
        return Body {
            .Name     = "Venus",
            .Mass     = 4.867e24,
            .Radius   = 6'051'800,
            .Position = {108'110'000'000, 0},
            .Velocity = {0, 35'020},
            .Color    = sf::Color::White,
        };
    }

    Body Body::Earth()
    {
        return Body {
            .Name     = "Earth",
            .Mass     = 5.792e24,
            .Radius   = 6'371'000,
            .Position = {149'600'000'000, 0},
            .Velocity = {0, 30'000},
            .Color    = sf::Color::Green,
        };
    }

    Body Body::EarthsMoon()
    {
        return Body {
            .Name     = "Earth's Moon",
            .Mass     = 7.34767309e22,
            .Radius   = 1'737'100,
            .Position = {Earth().Position.X + 384'400'000, 0},
            .Velocity = {0, Earth().Velocity.Y + 1'022},
            .Color    = sf::Color::White,
        };
    }

    Body Body::Mars()
    {
        return Body {
            .Name     = "Mars",
            .Mass     = 6.39e23,
            .Radius   = 3'389'500,
            .Position = {234'310'000'000, 0},
            .Velocity = {0, 24'000},
            .Color    = sf::Color::Red,
        };
    }
} // namespace SpaceSim