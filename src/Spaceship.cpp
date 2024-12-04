#include "Spaceship.hpp"
#include "Bullet.hpp"
#include "threepp/threepp.hpp"

using namespace threepp;


void Spaceship::createSpaceship() {
    //This will create the Craft
    mesh = OBJLoader().load("data/textures/Fighter_01.obj"); // Load the spaceship model
    mesh->scale.set(0.14f, 0.14f, 0.14f); // The scale
    mesh->rotation.x = math::PI / 2; //  This will make the Spaceship right way up
}
Spaceship::Spaceship(const std::shared_ptr<Scene>& scene) {
    //This will add the Spaceship to the scene
    createSpaceship();
    scene->add(mesh);
}


// Should have made it in another way
void Spaceship::update(float deltaTime) {

}

// Should also made it in another way
void Spaceship::draw(const std::shared_ptr<Scene>& scene) {

}


void Spaceship::moveUp() const {
    // this will make the Spaceship move
    mesh->position.x += moveSpeed * std::sin(mesh->rotation.y);
    mesh->position.y -= moveSpeed * std::cos(mesh->rotation.y);

    if (mesh->position.x <= -11) mesh->position.x = 11;
    else if (mesh->position.x >= 11) mesh->position.x = -11;

    if (mesh->position.y <= -11) mesh->position.y = 11;
    else if (mesh->position.y >= 11) mesh->position.y = -11;
}

void Spaceship::moveLeft() const {
    //this will make the Spaceship rotate left
    mesh->rotation.y += rotationSpeed;
}

void Spaceship::moveRight() const {
    //this will make the Spaceship rotate right
    mesh->rotation.y -= rotationSpeed;
}

void Spaceship::shoot(std::vector<std::shared_ptr<Bullet>>& bullets) const {
    //this will make the bullet shoot from Spacecraft
    Vector3 direction(std::sin(mesh->rotation.y), -std::cos(mesh->rotation.y), 0);
    Vector3 position = mesh->position + direction * 0.5f;
    bullets.emplace_back(std::make_shared<Bullet>(position, direction, 0.35f, 5.0f));
}

