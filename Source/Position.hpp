#pragma once

#include "Vector2.hpp"

#include <SFML/System/Vector2.hpp>

namespace SpaceSim
{
    class Position : public Vector2
    {
    };

    /// <summary>
    /// Calculate the distance between two positions.
    /// </summary>
    ///
    /// <param name="a">One of the positions.</param>
    /// <param name="a">One of the positions.</param>
    ///
    /// <returns>Distance between both positions.</returns>
    double DistanceBetween(const Position &a, const Position &b);

    /// <summary>
    /// Calculate the angle between two positions.
    /// </summary>
    ///
    /// <param name="a">One of the positions.</param>
    /// <param name="b">One of the positions.</param>
    ///
    /// <returns>Angle between two positions (radians).</returns>
    double AngleBetween(const Position &a, const Position &b);

    /// <summary>
    /// Convert a position to SFML coords.
    /// </summary>
    ///
    /// <param name="position">Position to convert.</param>
    ///
    /// <returns>SFML Coords.</returns>
    sf::Vector2f ToCoords(const Position &position);

    /// <summary>
    /// Convert a SFML coords to a Position.
    /// </summary>
    ///
    /// <param name="coords">Coords to convert.</param>
    ///
    /// <returns>Position.</returns>
    Position ToPosition(const sf::Vector2f &coords);
} // namespace SpaceSim