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
        float       Mass     = 0.f;
        float       Radius   = 0.f;
        Position    Position = {0.f, 0.f};
        Velocity    Velocity = {0.f, 0.f};
        sf::Color   Color    = sf::Color::Blue;

        static Body Sun();
        static Body Earth();
        static Body Mars();
    };

    float DistanceBetween(const Body &body, const Body &other);
    float AngleBetween(const Body &body, const Body &other);
    float GravitationalFieldStrength(const Body &body, const Body &other);
} // namespace SpaceSim