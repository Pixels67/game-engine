#include "Engine/Engine.hpp"
#include <SFML/Graphics.hpp>

constexpr size_t SCREEN_WIDTH = 800;
constexpr size_t SCREEN_HEIGHT = 600;
constexpr const char *WINDOW_TITLE = "Hello World!";

int main() {
    Engine::Engine engine;
    engine.CreateWindow(SCREEN_WIDTH, SCREEN_HEIGHT, WINDOW_TITLE);

    engine.CreateObject(Engine::Transform({0.0f, 0.0f}, {50.0f, 50.0f}));
    engine.CreateObject(Engine::Transform({100.0f, 0.0f}, {50.0f, 50.0f}));

    while (engine.IsRunning()) {
        engine.Tick();
    }
}
