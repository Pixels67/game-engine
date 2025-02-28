#pragma once

#include "GameObject.hpp"
#include "SFML/Graphics.hpp"

namespace Engine {
    class Renderer {
    public:
        Renderer();
        ~Renderer();

        void Render(sf::RenderWindow &window, ObjectPool &objectPool);
    };
} // Engine
