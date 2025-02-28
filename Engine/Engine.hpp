#pragma once

#include "GameObject.hpp"
#include "Renderer.hpp"
#include <SFML/Graphics.hpp>

namespace Engine {
class Engine {
public:
    Engine();
    ~Engine();

    void CreateWindow(size_t width, size_t height, const std::string &title);
    void CloseWindow();
    bool IsRunning() const;

    size_t CreateObject(Transform transform);
    void DestroyObject(size_t objectUid);

    void Tick();
    void Update();
    void Render();

private:
    sf::RenderWindow m_window;
    Renderer m_renderer;
    ObjectPool m_gameObjectPool;
};
} // namespace Engine
