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
        , m_Camera(m_Window, m_View)
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
        m_SolarSystem.AddBody(Body::Mercury());
        m_SolarSystem.AddBody(Body::Venus());
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

            m_Camera.OnEvent(event);

            switch (event.type)
            {
            case sf::Event::Closed: CloseWindow(); break;
            }
        }
    }

    void Application::DrawImGuiLayer()
    {
        ImGui::SetNextWindowPos({50, 50});
        ImGui::SetNextWindowSize({350, 600});

        ImGui::Begin("SpaceSim", nullptr, ImGuiWindowFlags_NoResize);

        DrawImGuiLayer_Settings();
        DrawImGuiLayer_Bodies();

        ImGui::End();
    }

    void Application::DrawImGuiLayer_Settings()
    {
        if (ImGui::CollapsingHeader("Settings"))
        {
            ImGui::Checkbox("Simulation Running", &m_SimulationActive);
            ImGui::Checkbox("ToScaleBodies", &ToScaleBodies);
            ImGui::InputDouble("TimeScale", &TimeScale);
        }
    }

    void Application::DrawImGuiLayer_Bodies()
    {
        if (ImGui::CollapsingHeader("Bodies"))
        {
            const auto &bodies = m_SolarSystem.GetBodies();

            ImGui::Text("System Age: %.1f years", m_SolarSystem.AgeInYears());
            ImGui::Text("Body Count: %d", bodies.size());

            if (ImGui::TreeNode("Bodies"))
            {
                for (const auto &body : bodies)
                {
                    if (ImGui::TreeNode(body.Name.c_str()))
                    {
                        ImGui::Text("Mass: %ekg", body.Mass);
                        ImGui::Text("Radius: %em", body.Radius);
                        ImGui::Text("Position: (%e,%e)", body.Position.X, body.Position.Y);
                        ImGui::Text("Velocity: (%e,%e)", body.Velocity.X, body.Velocity.Y);

                        if (ImGui::Button("Go To"))
                        {
                            const auto coords = ToCoords({body.Position.X + body.Radius,body.Position.Y + body.Radius});

                            m_View.setCenter(coords);
                            m_Window.setView(m_View);
                        }

                        ImGui::TreePop();
                    }
                }

                ImGui::TreePop();
            }
        }
    }

    void Application::CloseWindow()
    {
        m_Window.close();
    }
} // namespace SpaceSim