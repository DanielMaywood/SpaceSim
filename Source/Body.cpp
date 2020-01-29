#include "Body.hpp"

namespace SpaceSim
{
    float DistanceBetween(const Body &body, const Body &other)
    {
        return DistanceBetween(body.Position, other.Position);
    }

    float AngleBetween(const Body &body, const Body &other)
    {
        return AngleBetween(body.Position, other.Position);
    }

    float GravitationalFieldStrength(const Body &body, const Body &other)
    {
        static constexpr const float GravitationalConstant = 6.67e-11f;

        const float r = body.Radius + other.Radius + DistanceBetween(body, other);

        return (GravitationalConstant * other.Mass) / (r * r);
    }

    Body Body::Sun()
    {
        return Body {
            .Name   = "Sun",
            .Mass   = 1.989e30f,
            .Radius = 696'342'000.f,
            .Color  = sf::Color::Yellow,
        };
    }

    Body Body::Mercury()
    {
        return Body {
            .Name     = "Mercury",
            .Mass     = 3.285e23f,
            .Radius   = 2'439'700.f,
            .Position = {53'397'000'000.f, 0.f},
            .Velocity = {0.f, 48'000.f},
            .Color    = sf::Color::White,
        };
    }

    Body Body::Venus()
    {
        return Body {
            .Name     = "Venus",
            .Mass     = 4.867e24f,
            .Radius   = 6'051'800.f,
            .Position = {108'110'000'000.f, 0.f},
            .Velocity = {0.f, 35'020.f},
            .Color    = sf::Color::White,
        };
    }

    Body Body::Earth()
    {
        return Body {
            .Name     = "Earth",
            .Mass     = 5.792e24f,
            .Radius   = 6'371'000.f,
            .Position = {149'600'000'000.f, 0.f},
            .Velocity = {0.f, 30'000.f},
            .Color    = sf::Color::Green,
        };
    }

    Body Body::Mars()
    {
        return Body {
            .Name     = "Mars",
            .Mass     = 6.39e23f,
            .Radius   = 3'389'500.f,
            .Position = {234'310'000'000.f, 0.f},
            .Velocity = {0.f, 24'000.f},
            .Color    = sf::Color::Red,
        };
    }
} // namespace SpaceSim