#pragma once

#include "Body.hpp"

#include <SFML/Graphics.hpp>

#include <vector>

namespace SpaceSim
{
    class SolarSystem
    {
    public:
        void AddBody(Body body);
        void Update(double dt);

        void Draw(sf::RenderWindow &window) const;

    private:
        void UpdateBody(Body &body, double dt);

    private:
        std::vector<Body> m_Bodies;
    };
} // namespace SpaceSim