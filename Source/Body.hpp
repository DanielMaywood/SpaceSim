#pragma once

#include "Position.hpp"
#include "Velocity.hpp"

#include <SFML/Graphics/Color.hpp>

#include <string>

namespace SpaceSim
{
    struct Body
    {
        std::string Name;
        double      Mass     = 0.0;
        double      Radius   = 0.0;
        Position    Position = {0.0, 0.0};
        Velocity    Velocity = {0.0, 0.0};
        sf::Color   Color    = sf::Color::Blue;

        static Body Sun();
        static Body Mercury();
        static Body Venus();
        static Body Earth();
        static Body Mars();
    };

    double DistanceBetween(const Body &body, const Body &other);
    double AngleBetween(const Body &body, const Body &other);
    double GravitationalFieldStrength(const Body &body, const Body &other);
} // namespace SpaceSim