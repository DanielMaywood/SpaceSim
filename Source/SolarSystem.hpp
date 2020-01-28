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
        void Update(float dt);

        void Draw(sf::RenderWindow &window) const;

        std::vector<Body> &GetBodies();

    private:
        void UpdateBody(Body &body, float dt);

    private:
        std::vector<Body> m_Bodies;
    };
} // namespace SpaceSim