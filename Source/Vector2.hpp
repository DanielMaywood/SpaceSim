#pragma once

namespace SpaceSim
{
    struct Vector2
    {
        float X = 0.0;
        float Y = 0.0;

        Vector2 &operator+=(const Vector2 &other);
        Vector2 &operator-=(const Vector2 &other);
        Vector2 &operator*=(float scalar);
    };

    Vector2 operator+(Vector2 obj, const Vector2 &other);
    Vector2 operator-(Vector2 obj, const Vector2 &other);
    Vector2 operator*(Vector2 obj, float scalar);
} // namespace SpaceSim