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
        void Update(float dt);

        void Draw(sf::RenderWindow &window) const;

        float AgeInYears() const;

        std::vector<Body> &GetBodies();

    private:
        void UpdateBody(Body &body, float dt);

    private:
        std::vector<Body> m_Bodies;
        float             m_Time = 0.f;
    };
} // namespace SpaceSim