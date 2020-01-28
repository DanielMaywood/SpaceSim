#include "Body.hpp"

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

    Body Body::Sun()
    {
        return Body {
            .Mass   = 1.989e30,
            .Radius = 696'342'000,
            .Color  = sf::Color::Yellow,
        };
    }

    Body Body::Earth()
    {
        return Body {
            .Mass     = 5.792e24,
            .Radius   = 6'371'000.0,
            .Position = {149'600'000'000.0, 0.0},
            .Velocity = {0.0, 30'000.0},
            .Color    = sf::Color::Green,
        };
    }

    Body Body::Mars()
    {
        return Body {
            .Mass     = 6.39e23,
            .Radius   = 3'389'500.0,
            .Position = {234'310'000'000.0, 0.0},
            .Velocity = {0.0, 24'000.0},
            .Color    = sf::Color::Red,
        };
    }
} // namespace SpaceSim