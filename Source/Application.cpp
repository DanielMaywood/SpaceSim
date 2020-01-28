#include "Application.hpp"

#include "Settings.hpp"

#include <imgui-SFML.h>
#include <imgui.h>

#include <iostream>

namespace SpaceSim
{
    Application::Application(sf::RenderWindow &window)
        : m_Window(window)
        , m_View(window.getDefaultView())
        , m_SimulationActive(true)
    {
        const sf::Vector2 windowSize = window.getSize();

        m_View.setSize(static_cast<float>(windowSize.x), static_cast<float>(windowSize.y));
        m_View.setCenter(0.f, 0.f);

        m_Window.setView(m_View);
    }

    void Application::OnSetup()
    {
        ImGui::SFML::Init(m_Window);

        m_SolarSystem.AddBody(Body::Sun());
        m_SolarSystem.AddBody(Body::Earth());
        m_SolarSystem.AddBody(Body::Mars());
    }

    void Application::OnFrame(sf::Time dt)
    {

        if (m_SimulationActive)
        {
            m_SolarSystem.Update(dt.asSeconds() * TimeScale);
        }

        m_SolarSystem.Draw(m_Window);

        ImGui::SFML::Update(m_Window, dt);
        DrawImGuiLayer();
        ImGui::SFML::Render(m_Window);

        for (sf::Event event; m_Window.pollEvent(event);)
        {
            ImGui::SFML::ProcessEvent(event);

            switch (event.type)
            {
            case sf::Event::Closed: CloseWindow(); break;
            case sf::Event::MouseWheelMoved: ZoomInWindow(event); break;
            }
        }
    }

    void Application::DrawImGuiLayer()
    {
        ImGui::SetNextWindowPos({50, 50});

        ImGui::Begin("SpaceSim");

        /// ==== Settings

        if (ImGui::CollapsingHeader("Settings"))
        {
            ImGui::Checkbox("Simulation Running", &m_SimulationActive);
            ImGui::InputFloat("TimeScale", &TimeScale);
        }

        /// ==== Bodies

        if (ImGui::CollapsingHeader("Bodies"))
        {
            const auto &bodies = m_SolarSystem.GetBodies();

            ImGui::Text("Body Count: %d", bodies.size());

            if (ImGui::TreeNode("Bodies"))
            {
                for (const auto &body : bodies)
                {
                    if (ImGui::TreeNode(body.Name.c_str()))
                    {
                        ImGui::Text("Mass: %fkg", body.Mass);
                        ImGui::Text("Position: (%f,%f)", body.Position.X, body.Position.Y);
                        ImGui::Text("Velocity: (%f,%f)", body.Velocity.X, body.Velocity.Y);

                        ImGui::TreePop();
                    }
                }

                ImGui::TreePop();
            }
        }

        ImGui::End();
    }

    void Application::CloseWindow()
    {
        m_Window.close();
    }

    void Application::ZoomInWindow(const sf::Event &event)
    {
        m_View.zoom(event.mouseWheel.delta * -0.05f + 1.f);

        m_Window.setView(m_View);
    }
} // namespace SpaceSim