#ifndef GAME_OBJECT_HPP
#define GAME_OBJECT_HPP

#include "threepp/threepp.hpp"
#include <memory>

class GameObject {
public:
    virtual ~GameObject() = default;

    virtual void update(float deltaTime) = 0;
    virtual void draw(const std::shared_ptr<threepp::Scene>& scene) = 0;

    virtual void kill() { mesh = nullptr; } // Default implementation

    const threepp::Vector3& getPosition() const { return mesh->position; }

protected:
    std::shared_ptr<threepp::Object3D> mesh;
};

#endif // GAME_OBJECT_HPP
