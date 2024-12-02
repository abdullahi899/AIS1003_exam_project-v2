#include "Bullet.hpp"

using namespace threepp;

Bullet::Bullet(const Vector3 &position, const Vector3 &direction, float speed, float lifespan)
    : velocity(direction * speed), lifespan(lifespan) {
    auto geometry = SphereGeometry::create(0.2f, 16, 16);
    auto material = MeshBasicMaterial::create();
    material->color = Color::red;
    mesh = Mesh::create(geometry, material);
    mesh->position.copy(position);
}

void Bullet::update(float deltaTime) {
    mesh->position.add(velocity);
    lifespan -= deltaTime;
}

void Bullet::draw(const std::shared_ptr<Scene> &scene) {
    scene->add(mesh);
}

bool Bullet::isAlive() const {
    return lifespan > 0;
}
