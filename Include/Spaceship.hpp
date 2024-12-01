#ifndef SPACESHIP_HPP
#define SPACESHIP_HPP

#include "threepp/threepp.hpp"
#include "Bullet.hpp"

using namespace threepp;

class Spaceship {
public:
    explicit Spaceship(std::shared_ptr<Scene> &scene);

    void moveUp();
    void moveDown();
    void moveLeft();
    void moveRight();
    void shoot(std::vector<std::shared_ptr<Bullet>> &bullets);
    const threepp::Vector3 &getPosition() const; // Getter for position

private:
    std::shared_ptr<Group> spaceship;
    std::shared_ptr<Scene> &scene;
    float moveSpeed = 0.1f;
    float rotationSpeed = 0.04f;

    void createSpaceShip();
};

#endif // SPACESHIP_HPP
