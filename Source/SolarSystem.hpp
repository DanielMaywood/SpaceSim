#pragma once

#include "Body.hpp"

#include <SFML/Graphics/RenderWindow.hpp>

#include <vector>

namespace SpaceSim
{
    class SolarSystem
    {
    public:
        /// <summary>
        /// Add a Body to this SolarSystem.
        /// </summary>
        ///
        /// <param name="body">The body to add.</param>
        void AddBody(Body body);

        /// <summary>
        /// Updates the state of the SolarSystem and
        /// pass how much time has passed since last update.
        /// </summary>
        ///
        /// <param name="dt">Time since last call.</param>
        void Update(double dt);

        /// <summary>
        /// Draw the SolarSystem onto the RenderWindow.
        /// </summary>
        ///
        /// <param name="window">The window to render on.</param>
        void Draw(sf::RenderWindow &window) const;

        /// <summary>
        /// Get the age of the System in Earth years.
        /// </summary>
        ///
        /// <returns>The age of the System in Earth years.</returns>
        double AgeInEarthYears() const;

        /// <summary>
        /// Get a reference to the bodies stored in this System.
        /// </summary>
        ///
        /// <returns>The bodies in this System.</returns>
        std::vector<Body> &GetBodies();

    private:
        void UpdateBody(Body &body, double dt);

    private:
        std::vector<Body> m_Bodies;
        double            m_Time = 0.0;
    };
} // namespace SpaceSim