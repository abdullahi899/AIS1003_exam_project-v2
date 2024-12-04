#include "Asteroid.hpp"
#include <random>
#include <memory>

using namespace threepp;

Asteroid::Asteroid(const std::shared_ptr<Scene>& scene) {
    //This will create Asteroid
    std::shared_ptr<SphereGeometry> geometry = SphereGeometry::create(0.4f, 200, 200);
    std::shared_ptr<MeshBasicMaterial> material = MeshBasicMaterial::create();
    material->color = Color::black;
    mesh = Mesh::create(geometry, material);

    // Generate random position and velocity between -10 and +10 window, and 2 different speed
    std::random_device rd;
    std::mt19937 generator(rd());
    std::uniform_real_distribution<float> positionDist(10.f, 10.f);
    std::uniform_real_distribution<float> velocityDist(-0.05f, 0.05f);

    //This will add make the Asteroid spawn at random places
    mesh->position.set(positionDist(generator), positionDist(generator), 0);
    velocity = Vector3(velocityDist(generator), velocityDist(generator), 0);
    scene->add(mesh);
}

void Asteroid::update(float deltaTime) {

    //The Astroid will move
    mesh->position.add(velocity);

    // Astroid will not disappear from window/wrap around
    if (mesh->position.x < -10) mesh->position.x = 10;
    if (mesh->position.x > 10) mesh->position.x = -10;
    if (mesh->position.y < -10) mesh->position.y = 10;
    if (mesh->position.y > 10) mesh->position.y = -10;
}

void Asteroid::draw(const std::shared_ptr<Scene>& scene) {

}

void Asteroid::kill() {
    //Asteroid will be removed form screen and memory
    if (mesh && mesh->parent) {
        mesh->parent->remove(*mesh);
    }
}

std::vector<std::shared_ptr<Asteroid>> Asteroid::generateAsteroid(const std::shared_ptr<Scene>& scene, int count) {
    //Astroid will be stored her
    std::vector<std::shared_ptr<Asteroid>> astroids;
    for (int i = 1; i < count; ++i) {
        astroids.push_back(std::make_shared<Asteroid>(scene));
    }
    return astroids;
}