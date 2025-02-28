#pragma once

#include <vector>
#include <SFML/System.hpp>

namespace Engine {
    struct Transform {
        Transform(sf::Vector2f position, sf::Vector2f scale);

        sf::Vector2f position = sf::Vector2f(0.0f, 0.0f);
        sf::Vector2f scale = sf::Vector2f(1.0f, 1.0f);
    };

    class GameObject {
    public:
        friend class ObjectPool;

        explicit GameObject(Transform transform);
        ~GameObject();

        size_t GetUid() const;
        bool IsActive() const;

        sf::Vector2f GetPosition() const;
        sf::Vector2f GetScale() const;

    private:
        void Initialize(size_t uId);

        size_t m_uId = 0;
        bool m_isActive;
        Transform m_transform;
    };

    class ObjectPool {
    public:
        ObjectPool();
        ~ObjectPool();

        std::optional<GameObject> Get(size_t objectUid);

        size_t Push(GameObject &object);
        size_t Emplace(Transform transform);
        void Remove(size_t objectUid);

        template<typename Callable>
        void Iterate(const Callable &callback) {
            for (const auto &object : m_objects) {
                callback(object);
            }
        }

    private:
        std::vector<GameObject> m_objects;
    };
} // Engine
