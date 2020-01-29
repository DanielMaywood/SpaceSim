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
        , m_SimulationActive(false)
    {
        FixWindowView();
    }

    void Application::OnSetup()
    {
        ImGui::SFML::Init(m_Window);

        m_SolarSystem.AddBody(Body::Sun());
        m_SolarSystem.AddBody(Body::Mercury());
        m_SolarSystem.AddBody(Body::Venus());
        m_SolarSystem.AddBody(Body::Earth());
        m_SolarSystem.AddBody(Body::EarthsMoon());
        m_SolarSystem.AddBody(Body::Mars());
    }

    void Application::OnFrame(sf::Time dt)
    {
        ProcessSolarSystemOnFrame(dt);
        ProcessCameraOnFrame();
        ProcessSpawnerOnFrame();
        ProcessImGuiOnFrame(dt);

        ProcessEvents();
    }

    void Application::ProcessSolarSystemOnFrame(sf::Time dt)
    {
        if (m_SimulationActive)
        {
            m_SolarSystem.Update(dt.asSeconds() * TimeScale);
        }

        m_SolarSystem.Draw(m_Window);
    }

    void Application::ProcessCameraOnFrame()
    {
        m_Camera.Update();
    }

    void Application::ProcessSpawnerOnFrame()
    {
        m_Spawner.Draw(m_Window);
    }

    void Application::ProcessImGuiOnFrame(sf::Time dt)
    {
        ImGui::SFML::Update(m_Window, dt);
        DrawImGuiLayer();
        ImGui::SFML::Render(m_Window);
    }

    void Application::ProcessEvents()
    {
        for (sf::Event event; m_Window.pollEvent(event);)
        {
            ProcessImGuiOnEvent(event);
            ProcessCameraOnEvent(event);

            switch (event.type)
            {
            case sf::Event::Closed: m_Window.close(); break;
            }
        }
    }

    void Application::ProcessImGuiOnEvent(const sf::Event &event)
    {
        ImGui::SFML::ProcessEvent(event);
    }

    void Application::ProcessCameraOnEvent(const sf::Event &event)
    {
        m_Camera.OnEvent(event);
    }

    void Application::DrawImGuiLayer()
    {
        ImGui::SetNextWindowPos({50, 50});
        ImGui::SetNextWindowSize({350, 600});

        ImGui::Begin("SpaceSim", nullptr, ImGuiWindowFlags_NoResize);

        DrawImGuiLayer_Settings();
        DrawImGuiLayer_Bodies();
        DrawImGuiLayer_Spawner();

        ImGui::End();
    }

    void Application::DrawImGuiLayer_Settings()
    {
        if (ImGui::CollapsingHeader("Settings"))
        {
            ImGui::Checkbox("Simulation Running", &m_SimulationActive);
            ImGui::Checkbox("ToScaleBodies", &ToScaleBodies);
            ImGui::InputFloat("ZoomScale", &ZoomScale);
            ImGui::InputDouble("TimeScale", &TimeScale);
        }
    }

    void Application::DrawImGuiLayer_Bodies()
    {
        if (ImGui::CollapsingHeader("Bodies"))
        {
            const auto &bodies = m_SolarSystem.GetBodies();

            ImGui::Text("System Age: %.1f Earth Years", m_SolarSystem.AgeInEarthYears());
            ImGui::Text("Body Count: %d", bodies.size());

            if (ImGui::Button("Stop Tracking"))
            {
                m_Camera.TrackPosition(nullptr);
            }

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
                            m_View.setCenter(ToCoords(body.Position));
                            m_Window.setView(m_View);
                        }

                        if (ImGui::Button("Track"))
                        {
                            m_Camera.TrackPosition(&body.Position);
                        }

                        ImGui::TreePop();
                    }
                }

                ImGui::TreePop();
            }
        }
    }

    void Application::DrawImGuiLayer_Spawner()
    {
        if (ImGui::CollapsingHeader("Spawner"))
        {
            m_Spawner.SetActive(true);

            auto &body = m_Spawner.GetBody();

            ImGui::InputText("Name", body.Name.data(), body.Name.size());

            ImGui::InputDouble("Pos X", &body.Position.X);
            ImGui::InputDouble("Pos Y", &body.Position.Y);

            if (ImGui::Button("Set Position As Center"))
            {
                body.Position = ToPosition(m_View.getCenter());
            }

            ImGui::InputDouble("Mass", &body.Mass);
            ImGui::InputDouble("Radius", &body.Radius);

            if (ImGui::Button("Spawn"))
            {
                m_Spawner.Spawn(m_SolarSystem);
            }
        }
        else
        {
            m_Spawner.SetActive(false);
        }
    }

    void Application::FixWindowView()
    {
        const sf::Vector2 windowSize = m_Window.getSize();

        m_View.setSize(static_cast<float>(windowSize.x), -static_cast<float>(windowSize.y));
        m_View.setCenter(0.f, 0.f);

        m_Window.setView(m_View);
    }

} // namespace SpaceSim