#include "Spawner.hpp"

#include "Settings.hpp"

#include <SFML/Graphics/CircleShape.hpp>

namespace SpaceSim
{
    void Spawner::Spawn(SolarSystem &solarSystem)
    {
        solarSystem.AddBody(m_BodyToSpawn);

        m_BodyToSpawn = Body();
    }

    void Spawner::SetActive(bool state)
    {
        m_Active = state;
    }

    void Spawner::Draw(sf::RenderWindow &window)
    {
        if (!m_Active)
        {
            return;
        }

        m_BodyToSpawn.Draw(window);
    }

    Body &Spawner::GetBody()
    {
        return m_BodyToSpawn;
    }
} // namespace SpaceSim
