#include "Astroid.hpp"
#include <random>

using namespace threepp;

Astroid::Astroid(std::shared_ptr<Scene> scene) {
    // Create asteroid geometry
    auto geometry = SphereGeometry::create(0.5f, 200, 200);
    auto material = MeshBasicMaterial::create();
    material->color = Color::black;

    mesh = Mesh::create(geometry, material);

    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_real_distribution<float> positionDist(-10.f, 10.0f);

    // Randomize position for X, Y, and Z coordinates
    mesh->position.set(positionDist(gen), positionDist(gen), positionDist(gen));


    // Randomize velocity
    std::uniform_real_distribution<float> velocityDist(-0.06f, 0.05f);
    velocity = Vector3(velocityDist(gen), velocityDist(gen), 0.01);

    scene->add(mesh);
}

void Astroid::update() {
    // Update position
    mesh->position.add(velocity);

    if (mesh->position.x <= -11) {
        mesh->position.x = 11;
    }else
        if (mesh->position.x >= 11) {
            mesh->position.x = -11;
        }else
            if (mesh->position.z <= -11) {
                mesh->position.z = 11;

            } else
                if (mesh->position.z >= 11) {
                    mesh->position.z = -11;

                }

    // Wrap around screen edges
    if (mesh->position.x > 10) mesh->position.x = -10;
    if (mesh->position.x < -10) mesh->position.x = 10;
    if (mesh->position.y > 10) mesh->position.y = -10;
    if (mesh->position.y < -10) mesh->position.y = 10;
}


std::vector<std::shared_ptr<Astroid>> Astroid::generateAstroids(
    std::shared_ptr<Scene> scene, int count) {
    std::vector<std::shared_ptr<Astroid>> astroids;
    for (int i = 0; i < count; ++i) {
        astroids.push_back(std::make_shared<Astroid>(scene));
    }
    return astroids;
}


