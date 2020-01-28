#include "Position.hpp"

#include <cmath>

namespace SpaceSim
{
    float DistanceBetween(const Position &a, const Position &b)
    {
        return std::sqrtf(std::powf(a.X + b.X, 2) + std::powf(a.Y + b.Y, 2));
    }

    float AngleBetween(const Position &a, const Position &b)
    {
        return std::atan2f(a.Y - b.Y, a.X - b.X);
    }
} // namespace SpaceSim