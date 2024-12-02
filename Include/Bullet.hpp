#ifndef BULLET_HPP
#define BULLET_HPP

#include "Collison helper.hpp"
#include <memory>

#include "Conector.hpp"

class Bullet : public GameObject {
public:
    void kill() {

    }
    Bullet(const threepp::Vector3 &position, const threepp::Vector3 &direction, float speed, float lifespan);

    void update(float deltaTime) override;
    void draw(const std::shared_ptr<threepp::Scene> &scene) override;

    bool isAlive() const;
    void setSpeed(float speed);

private:
    threepp::Vector3 velocity;
    float lifespan;
};

#endif // BULLET_HPP
