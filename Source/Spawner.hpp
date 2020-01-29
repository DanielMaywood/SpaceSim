#pragma once

#include "Body.hpp"
#include "Position.hpp"
#include "SolarSystem.hpp"
#include "Velocity.hpp"

#include <SFML/Graphics/Color.hpp>
#include <SFML/Graphics/RenderWindow.hpp>

namespace SpaceSim
{
    class Spawner
    {
    public:
        /// <summary>
        /// Spawn the current Body with the settings
        /// stored and reset the internal Body state
        /// with the default Body.
        /// </summary>
        void Spawn(SolarSystem &solarSystem);

        /// <summary>
        /// Set whether or not the Spawner is currently being used.
        /// When active, it draws the new Body without spawning it.
        /// </summary>
        ///
        /// <param name="state">The new state of the Spawner.</param>
        void SetActive(bool state);

        /// <summary>
        /// Draws the internal Body to the RenderWindow *if* the
        /// Spawner is in it's Active state.
        /// </summary>
        void Draw(sf::RenderWindow &window);

        /// <summary>
        /// Get a reference to the internal Body state.
        /// </summary>
        ///
        /// <returns>Get the internal Body state.</returns>
        Body &GetBody();

    private:
        bool m_Active;

        Body m_BodyToSpawn;
    };
} // namespace SpaceSim