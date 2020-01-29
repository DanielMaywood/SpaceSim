#include "Position.hpp"

#include "Settings.hpp"

#include <cmath>

namespace SpaceSim
{
    double DistanceBetween(const Position &a, const Position &b)
    {
        return std::sqrt(std::pow(a.X + b.X, 2) + std::pow(a.Y + b.Y, 2));
    }

    double AngleBetween(const Position &a, const Position &b)
    {
        return std::atan2(a.Y - b.Y, a.X - b.X);
    }

    sf::Vector2f ToCoords(const Position &position)
    {
        return {static_cast<float>(position.X * PixelPerM),static_cast<float>(position.Y * PixelPerM)};
    }
} // namespace SpaceSim