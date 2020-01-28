#include "Vector2.hpp"

namespace SpaceSim
{
    Vector2 &Vector2::operator+=(const Vector2 &other)
    {
        X += other.X;
        Y += other.Y;

        return *this;
    }

    Vector2 &Vector2::operator-=(const Vector2 &other)
    {
        X -= other.X;
        Y -= other.Y;

        return *this;
    }

    Vector2 &Vector2::operator*=(float scalar)
    {
        X *= scalar;
        Y *= scalar;

        return *this;
    }

    Vector2 operator+(Vector2 obj, const Vector2 &other)
    {
        return obj += other;
    }

    Vector2 operator-(Vector2 obj, const Vector2 &other)
    {
        return obj -= other;
    }

    Vector2 operator*(Vector2 obj, float scalar)
    {
        return obj *= scalar;
    }
} // namespace SpaceSim