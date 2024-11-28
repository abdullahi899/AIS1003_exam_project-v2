#ifndef SPACESHIP_HPP
#define SPACESHIP_HPP

#include "threepp/threepp.hpp"

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
    void shoot() {

        }




    // Ensure that the position is inherited or accessible
private:
    std::shared_ptr<Group> spaceship;
    std::shared_ptr<Scene> &scene;
    float moveSpeed = 0.2f;
    float rotationSpeed = 0.04f;

    void createSpaceShip() {
        spaceship = OBJLoader().load("data/textures/Fighter_01.obj");
        spaceship->scale.set(0.08, 0.08, 0.08);
        spaceship->position.x = (std::numbers::pi);
        scene->add(spaceship);
    }
};

#endif// SPACESHIP_HPP
