#ifndef SPACESHIP_HPP
#define SPACESHIP_HPP

#include "threepp/threepp.hpp"
#include "Bullet.hpp"

using namespace threepp;

class Spaceship {
public:
    Spaceship(std::shared_ptr<Scene> &scene) : scene(scene) { createSpaceShip(); }


    void moveUp() {
        spaceship->position.x += moveSpeed * std::sin(spaceship->rotation.y);
        spaceship->position.z += moveSpeed * std::cos(spaceship->rotation.y);
        if (spaceship->position.x <= -11) {
            spaceship->position.x = 11;
        }else
        if (spaceship->position.x >= 11) {
            spaceship->position.x = -11;
        }else
        if (spaceship->position.z <= -11) {
            spaceship->position.z = 11;

        } else
        if (spaceship->position.z >= 11) {
            spaceship->position.z = -11;

        }

    }

    void moveDown() {
        spaceship->position.x += moveSpeed * std::sin(spaceship->rotation.y);
        spaceship->position.z += moveSpeed * std::cos(spaceship->rotation.y);
    }

    void moveLeft() {
        spaceship->rotation.y += rotationSpeed;
    }

    void moveRight() {
        spaceship->rotation.y -= rotationSpeed;
    }
    void shoot(std::vector<std::shared_ptr<Bullet>> &bullets) {
        auto direction = Vector3(std::sin(spaceship->rotation.y), 1, std::cos(spaceship->rotation.y)).normalize();
        auto position = spaceship->position + direction * 0.1f; // Offset in front of the spaceship

        bullets.emplace_back(std::make_shared<Bullet>(position, direction, 0.35f, 5.0f));
    }






private:
    std::shared_ptr<Group> spaceship;
    std::shared_ptr<Scene> &scene;
    float moveSpeed = 0.1f;
    float rotationSpeed = 0.04f;

    void createSpaceShip() {
        spaceship = OBJLoader().load("data/textures/Fighter_01.obj");
        spaceship->scale.set(0.14, 0.14, 0.14);
        spaceship->position.x = (std::numbers::pi);
        scene->add(spaceship);
    }
};

#endif// SPACESHIP_HPP
