#pragma once

#include "Body.hpp"

#include <SFML/Graphics/RenderWindow.hpp>

#include <vector>

namespace SpaceSim
{
    class SolarSystem
    {
    public:
        void AddBody(Body body);
        void Update(double dt);

        void Draw(sf::RenderWindow &window) const;

        double AgeInEarthYears() const;

        std::vector<Body> &GetBodies();

    private:
        void UpdateBody(Body &body, double dt);

    private:
        std::vector<Body> m_Bodies;
        double             m_Time = 0.0;
    };
} // namespace SpaceSim