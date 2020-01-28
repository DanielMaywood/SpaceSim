#pragma once

#include "Vector2.hpp"

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
    /// <param name="a">One of the positions.</param>
    ///
    /// <returns>Angle between two positions (radians).</returns>
    double AngleBetween(const Position &a, const Position &b);
} // namespace SpaceSim