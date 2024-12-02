#include "Spaceship.hpp"
#include "threepp/threepp.hpp"
#include "Bullet.hpp"

using namespace threepp;

Spaceship::Spaceship(const std::shared_ptr<Scene> &scene) {
    createSpaceship();
    scene->add(mesh);
}

void Spaceship::createSpaceship() {
    mesh = OBJLoader().load("data/textures/Fighter_01.obj"); // Group type is compatible with Object3D
    mesh->scale.set(0.14f, 0.14f, 0.14f);
    mesh->rotation.x = math::PI / 2;
}

void Spaceship::update(float deltaTime) {
}

void Spaceship::draw(const std::shared_ptr<Scene> &scene) {
}


void Spaceship::moveUp() {
    mesh->position.x += moveSpeed * std::sin(mesh->rotation.y);
    mesh->position.y -= moveSpeed * std::cos(mesh->rotation.y);
    if (mesh->position.x <= -11) {
        mesh->position.x = 11;
    } else if (mesh->position.x >= 11) {
        mesh->position.x = -11;
    } else if (mesh->position.y <= -11) {
        mesh->position.y = 11;
    } else if (mesh->position.y >= 11) {
        mesh->position.y = -11;
    }

}

void Spaceship::moveLeft() {
    mesh->rotation.y += rotationSpeed;
}

void Spaceship::moveRight() {
    mesh->rotation.y -= rotationSpeed;
}

void Spaceship::shoot(std::vector<std::shared_ptr<Bullet> > &bullets) {
    Vector3 direction = Vector3(std::sin(mesh->rotation.y), -std::cos(mesh->rotation.y), 0);
    Vector3 position = mesh->position + direction * 0.5f;
    bullets.emplace_back(std::make_shared<Bullet>(position, direction, 0.35f, 5.0f));
}
void Spaceship::setSpeed(float speed) {
    moveSpeed = speed;
}
