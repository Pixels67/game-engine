#include <optional>
#include "GameObject.hpp"

Engine::Transform::Transform(const sf::Vector2f position, const sf::Vector2f scale)
: position(position)
, scale(scale)
{}

Engine::GameObject::GameObject(const Transform transform)
: m_isActive(false)
, m_transform(transform)
{}

Engine::GameObject::~GameObject() = default;

size_t Engine::GameObject::GetUid() const {
    return m_uId;
}

bool Engine::GameObject::IsActive() const {
    return m_isActive;
}

sf::Vector2f Engine::GameObject::GetPosition() const {
    return m_transform.position;
}

sf::Vector2f Engine::GameObject::GetScale() const {
    return m_transform.scale;
}

void Engine::GameObject::Initialize(const size_t uId) {
    m_uId = uId;
    m_isActive = true;
}

Engine::ObjectPool::ObjectPool() = default;

Engine::ObjectPool::~ObjectPool() = default;

std::optional<Engine::GameObject> Engine::ObjectPool::Get(const size_t objectUid) {
    for (auto& object : m_objects) {
        if (object.GetUid() != objectUid) continue;
        return object;
    }

    return std::nullopt;
}

size_t Engine::ObjectPool::Push(GameObject &object) {
    object.Initialize(m_objects.size());
    m_objects.push_back(object);
    return object.GetUid();
}

size_t Engine::ObjectPool::Emplace(Transform transform) {
    GameObject object = m_objects.emplace_back(transform);
    object.Initialize(m_objects.size() - 1);
    return object.GetUid();
}

void Engine::ObjectPool::Remove(const size_t objectUid) {
    for (size_t i = 0; i < m_objects.size(); i++) {
        if (m_objects[i].GetUid() != objectUid) continue;
        m_objects.erase(m_objects.begin() + i);
    }
}
