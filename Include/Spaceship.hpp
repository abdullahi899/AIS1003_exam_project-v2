#ifndef SPACESHIP_HPP
#define SPACESHIP_HPP

#include "CollistionHandler.hpp"
#include <vector>
#include <memory>

#include "Conector.hpp"
#include "threepp/threepp.hpp"

using namespace threepp;

class Spaceship : public GameObject {
public:
    explicit Spaceship(const std::shared_ptr<threepp::Scene> &scene);

    void update(float deltaTime) override;

    void draw(const std::shared_ptr<threepp::Scene> &scene) override;

    void moveUp();

    void moveLeft();

    void moveRight();

    void shoot(std::vector<std::shared_ptr<Bullet>>& bullets);

    void setSpeed(float speed);

private:
    float moveSpeed = 0.1f;
    float rotationSpeed = 0.04f;

    void createSpaceship();
};

#endif // SPACESHIP_HPP