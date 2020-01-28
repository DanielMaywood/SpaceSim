#pragma once

#include "Position.hpp"
#include "Velocity.hpp"

#include <SFML/Graphics/Color.hpp>

namespace SpaceSim
{
    struct Body
    {
        double    Mass     = 0.f;
        double    Radius   = 0.f;
        Position  Position = {0.f, 0.f};
        Velocity  Velocity = {0.f, 0.f};
        sf::Color Color    = sf::Color::Blue;

        static Body Sun();
        static Body Earth();
        static Body Mars();
    };

    double DistanceBetween(const Body &body, const Body &other);
    double AngleBetween(const Body &body, const Body &other);
    double GravitationalFieldStrength(const Body &body, const Body &other);
} // namespace SpaceSim