#include "Renderer.hpp"

Engine::Renderer::Renderer() = default;
Engine::Renderer::~Renderer() = default;

void Engine::Renderer::Render(sf::RenderWindow &window, ObjectPool &objectPool) {
    auto render = [&](const GameObject &gameObject) {
        sf::RectangleShape rect;
        rect.setFillColor(sf::Color::White);
        rect.setPosition(gameObject.GetPosition());
        rect.setSize(gameObject.GetScale());
        window.draw(rect);
    };

    objectPool.Iterate(render);
}
