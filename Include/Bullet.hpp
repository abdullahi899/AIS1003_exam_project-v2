#ifndef BULLET_HPP
#define BULLET_HPP

#include "threepp/threepp.hpp"
#include <memory>


class Bullet {
public:
    Bullet(const threepp::Vector3 &position, const threepp::Vector3 &direction, float speed, float lifespan);

    void update(float deltaTime);
    bool isAlive() const;
    void draw(const std::shared_ptr<threepp::Scene> &scene);

    const threepp::Vector3 &getPosition() const;

private:
    std::shared_ptr<threepp::Mesh> mesh;
    threepp::Vector3 velocity;
    float lifespan;
};

#endif // BULLET_HPP
