#pragma once

namespace SpaceSim
{
    struct Vector2
    {
        double X = 0.0;
        double Y = 0.0;

        Vector2 &operator+=(const Vector2 &other);
        Vector2 &operator-=(const Vector2 &other);
        Vector2 &operator*=(double scalar);
    };

    Vector2 operator+(Vector2 obj, const Vector2 &other);
    Vector2 operator-(Vector2 obj, const Vector2 &other);
    Vector2 operator*(Vector2 obj, double scalar);
} // namespace SpaceSim