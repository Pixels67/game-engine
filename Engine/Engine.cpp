#include "Engine.hpp"

namespace Engine {
    Engine::Engine() = default;
    Engine::~Engine() = default;

    void Engine::CreateWindow(const size_t width, const size_t height, const std::string &title) {
        m_window = sf::RenderWindow(
            sf::VideoMode({static_cast<unsigned>(width), static_cast<unsigned>(height)}), title
        );
    }

    void Engine::CloseWindow() {
        m_window.close();
    }

    bool Engine::IsRunning() const {
        return m_window.isOpen();
    }

    size_t Engine::CreateObject(const Transform transform) {
        return m_gameObjectPool.Emplace(transform);
    }

    void Engine::DestroyObject(const size_t objectUid) {
        m_gameObjectPool.Remove(objectUid);
    }

    void Engine::Tick() {
        while (const std::optional event = m_window.pollEvent()) {
            if (event->is<sf::Event::Closed>())
                CloseWindow();
        }

        Update();
        Render();
    }

    void Engine::Update() {
    }

    void Engine::Render() {
        m_window.clear(sf::Color::Black);
        m_renderer.Render(m_window, m_gameObjectPool);
        m_window.display();
    }
} // Engine
