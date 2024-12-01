#include "Spaceship.hpp"

Spaceship::Spaceship(std::shared_ptr<Scene> &scene) : scene(scene) {
    createSpaceShip();
}

void Spaceship::createSpaceShip() {
    spaceship = OBJLoader().load("data/textures/Fighter_01.obj");
    spaceship->scale.set(0.14, 0.14, 0.14);
    spaceship->position.x = (std::numbers::pi);
    scene->add(spaceship);
}

void Spaceship::moveUp() {
    spaceship->position.x += moveSpeed * std::sin(spaceship->rotation.y);
    spaceship->position.z += moveSpeed * std::cos(spaceship->rotation.y);

    if (spaceship->position.x <= -11) {
        spaceship->position.x = 11;
    } else if (spaceship->position.x >= 11) {
        spaceship->position.x = -11;
    }
    if (spaceship->position.z <= -11) {
        spaceship->position.z = 11;
    } else if (spaceship->position.z >= 11) {
        spaceship->position.z = -11;
    }
}

void Spaceship::moveDown() {
    spaceship->position.x += moveSpeed * std::sin(spaceship->rotation.y);
    spaceship->position.z += moveSpeed * std::cos(spaceship->rotation.y);
}

void Spaceship::moveLeft() {
    spaceship->rotation.y += rotationSpeed;
}

void Spaceship::moveRight() {
    spaceship->rotation.y -= rotationSpeed;
}

void Spaceship::shoot(std::vector<std::shared_ptr<Bullet>> &bullets) {
    auto direction = Vector3(std::sin(spaceship->rotation.y), 1, std::cos(spaceship->rotation.y)).normalize();
    auto position = spaceship->position + direction * 0.1f; // Offset in front of the spaceship

    bullets.emplace_back(std::make_shared<Bullet>(position, direction, 0.35f, 5.0f));
}

const Vector3 &Spaceship::getPosition() const {
    return spaceship->position;
}


