#pragma once

#include "SolarSystem.hpp"
#include "Velocity.hpp"
#include "Position.hpp"
#include "Body.hpp"

#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics/Color.hpp>

namespace SpaceSim
{
    class Spawner
    {
    public:
        void Spawn(SolarSystem& solarSystem);
        void SetActive(bool state);
        void Draw(sf::RenderWindow &window);

        Body &GetBody();

    private:
        bool m_Active;

        Body m_BodyToSpawn;
    };
} // namespace SpaceSim