#include "Spaceship.hpp"
#include "Bullet.hpp"
#include "threepp/threepp.hpp"

using namespace threepp;

Spaceship::Spaceship(const std::shared_ptr<Scene>& scene) {
    createSpaceship();
    scene->add(mesh); // Add the spaceship mesh to the scene
}

void Spaceship::createSpaceship() {
    mesh = OBJLoader().load("data/textures/Fighter_01.obj"); // Load the spaceship model
    mesh->scale.set(0.14f, 0.14f, 0.14f); // Set scale
    mesh->rotation.x = math::PI / 2; // Rotate for proper orientation
}

// Implement the update method
void Spaceship::update(float deltaTime) {
    // Example: Could handle animations or continuous updates
}

// Implement the draw method
void Spaceship::draw(const std::shared_ptr<Scene>& scene) {
    if (mesh) {
        scene->add(mesh); // Add the spaceship mesh to the scene if it exists
    }
}

// Other member functions
void Spaceship::moveUp() {
    mesh->position.x += moveSpeed * std::sin(mesh->rotation.y);
    mesh->position.y -= moveSpeed * std::cos(mesh->rotation.y);

    if (mesh->position.x <= -11) mesh->position.x = 11;
    else if (mesh->position.x >= 11) mesh->position.x = -11;

    if (mesh->position.y <= -11) mesh->position.y = 11;
    else if (mesh->position.y >= 11) mesh->position.y = -11;
}

void Spaceship::moveLeft() {
    mesh->rotation.y += rotationSpeed;
}

void Spaceship::moveRight() {
    mesh->rotation.y -= rotationSpeed;
}

void Spaceship::shoot(std::vector<std::shared_ptr<Bullet>>& bullets) {
    Vector3 direction(std::sin(mesh->rotation.y), -std::cos(mesh->rotation.y), 0);
    Vector3 position = mesh->position + direction * 0.5f;
    bullets.emplace_back(std::make_shared<Bullet>(position, direction, 0.35f, 5.0f));
}

