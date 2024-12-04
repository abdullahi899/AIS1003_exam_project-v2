#ifndef SPACESHIP_HPP
#define SPACESHIP_HPP

#include "Bullet.hpp"
#include <vector>
#include <memory>
#include "GameObject.hpp"
#include "threepp/threepp.hpp"

using namespace threepp;

class Spaceship : public GameObject {
public:
    explicit Spaceship(const std::shared_ptr<Scene> &scene);

    void update(float deltaTime) override;

    void draw(const std::shared_ptr<Scene> &scene) override;

    void moveUp() const;

    void moveLeft() const;

    void moveRight() const;

    void shoot(std::vector<std::shared_ptr<Bullet>>& bullets) const;

    void setSpeed(float speed);



private:
    float moveSpeed = 0.1f;
    float rotationSpeed = 0.04f;

    void createSpaceship();
};

#endif // SPACESHIP_HPP