#include "Astroid.hpp"
#include <random>

using namespace threepp;

Astroid::Astroid(const std::shared_ptr<Scene> &scene) {
    auto geometry = SphereGeometry::create(0.4f, 200, 200);
    auto material = MeshBasicMaterial::create();
    material->color = Color::black;
    mesh = Mesh::create(geometry, material);

    std::random_device rd;
    std::mt19937 make(rd());
    std::uniform_real_distribution<float> positionDist(-10.f, 10.0f);
    mesh->position.set(positionDist(make), positionDist(make), 0);

    std::uniform_real_distribution<float> velocityDist(-0.06f, 0.05f);
    velocity = Vector3(velocityDist(make), velocityDist(make), velocityDist(make));

    scene->add(mesh);
}

void Astroid::update(float deltaTime) {
    mesh->position.add(velocity);
    if (mesh->position.x < -10) mesh->position.x = 10;
    if (mesh->position.x > 10) mesh->position.x = -10;
    if (mesh->position.y < -10) mesh->position.y = 10;
    if (mesh->position.y> 10) mesh->position.y = -10;
}


void Astroid::draw(const std::shared_ptr<Scene> &scene) {
    scene->add(mesh);
}


std::vector<std::shared_ptr<Astroid> > Astroid::generateAstroids(const std::shared_ptr<Scene> &scene, int count) {
    std::vector<std::shared_ptr<Astroid> > astroids;
    for (int i = 0; i < count; ++i) {
        astroids.push_back(std::make_shared<Astroid>(scene));
    }
    return astroids;
}
