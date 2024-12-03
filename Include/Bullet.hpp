#ifndef BULLET_HPP
#define BULLET_HPP

#include "Conector.hpp"
#include "threepp/threepp.hpp"
#include <memory>

class Bullet : public GameObject {
public:
    Bullet(const threepp::Vector3& position, const threepp::Vector3& direction, float speed, float lifespan);

    void update(float deltaTime) override;
    void draw(const std::shared_ptr<threepp::Scene>& scene) override;
    void kill();
    bool isAlive() const;

private:
    threepp::Vector3 velocity;
    float lifespan;
};

#endif // BULLET_HPP
