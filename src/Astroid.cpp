#include "Astroid.hpp"
#include <random>
#include <memory>

using namespace threepp;

Astroid::Astroid(const std::shared_ptr<Scene>& scene) {
    auto geometry = SphereGeometry::create(0.4f, 200, 200);
    auto material = MeshBasicMaterial::create();
    material->color = Color::black;
    mesh = Mesh::create(geometry, material);

    // Generate random position and velocity
    std::random_device rd;
    std::mt19937 generator(rd());
    std::uniform_real_distribution<float> positionDist(-10.f, 10.f);
    std::uniform_real_distribution<float> velocityDist(-0.06f, 0.05f);

    mesh->position.set(positionDist(generator), positionDist(generator), 0);
    velocity = Vector3(velocityDist(generator), velocityDist(generator), 0);

    scene->add(mesh);
}

void Astroid::update(float deltaTime) {
    if (!mesh) return; // Skip update if the asteroid has been "killed"

    mesh->position.add(velocity);

    // Wrap around the screen edges
    if (mesh->position.x < -10) mesh->position.x = 10;
    if (mesh->position.x > 10) mesh->position.x = -10;
    if (mesh->position.y < -10) mesh->position.y = 10;
    if (mesh->position.y > 10) mesh->position.y = -10;
}

void Astroid::draw(const std::shared_ptr<Scene>& scene) {
    if (mesh) {
        scene->add(mesh);
    }
}

void Astroid::kill() {
    if (mesh && mesh->parent) {
        mesh->parent->remove(*mesh);
    }
}

std::vector<std::shared_ptr<Astroid>> Astroid::generateAstroids(const std::shared_ptr<Scene>& scene, int count) {
    std::vector<std::shared_ptr<Astroid>> astroids;
    for (int i = 1; i < count; ++i) {
        astroids.push_back(std::make_shared<Astroid>(scene));
    }
    return astroids;
}
