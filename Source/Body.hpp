#pragma once

#include "Position.hpp"
#include "Velocity.hpp"

#include <SFML/Graphics/Color.hpp>
#include <SFML/Graphics/RenderWindow.hpp>

#include <string>

namespace SpaceSim
{
    struct Body
    {
        std::string Name     = std::string(50, '\0');
        double      Mass     = 0.0;
        double      Radius   = 0.0;
        Position    Position = {0.0, 0.0};
        Velocity    Velocity = {0.0, 0.0};
        sf::Color   Color    = sf::Color::Blue;

        void Draw(sf::RenderWindow &window) const;

        static Body Sun();
        static Body Mercury();
        static Body Venus();
        static Body Earth();
        static Body EarthsMoon();
        static Body Mars();
    };

    /// <summary>
    /// Calculate the distance between two Bodies.
    /// </summary>
    ///
    /// <param name="body">One of the Bodies.</param>
    /// <param name="other">One of the Bodies.</param>
    ///
    /// <returns>Distance between both Bodies.</returns>
    double DistanceBetween(const Body &body, const Body &other);

    /// <summary>
    /// Calculate the angle between two Bodies.
    /// </summary>
    ///
    /// <param name="body">One of the bodies..</param>
    /// <param name="other">The other body.</param>
    ///
    /// <returns>Angle between two bodies (radians).</returns>
    double AngleBetween(const Body &body, const Body &other);

    /// <summary>
    /// Calculate the Gravitational Field Strength between two Bodies.
    /// </summary>
    ///
    /// <param name="body">One of the Bodies.</param>
    /// <param name="other">One of the Bodies.</param>
    ///
    /// <returns>Gravitational Field Strength between both Bodies.</returns>
    double GravitationalFieldStrength(const Body &body, const Body &other);

    /// <summary>
    /// Calculate the Centripetal Acceleration between two Bodies.
    /// </summary>
    ///
    /// <param name="body">One of the Bodies.</param>
    /// <param name="other">One of the Bodies.</param>
    ///
    /// <returns>Centripetal Acceleration between both Bodies.</returns>
    double CentripetalAcceleration(const Body &body, const Body &other);
} // namespace SpaceSim