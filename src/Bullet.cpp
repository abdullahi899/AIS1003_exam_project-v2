#include "Bullet.hpp"

using namespace threepp;

Bullet::Bullet(const Vector3& position, const Vector3& direction, float speed, float lifespan)
    : velocity(direction * speed), lifespan(lifespan) {
    auto geometry = SphereGeometry::create(0.2f, 16, 16);
    auto material = MeshBasicMaterial::create();
    material->color = Color::red;
    mesh = Mesh::create(geometry, material);
    mesh->position.copy(position);
}

void Bullet::update(float deltaTime) {
    if (!mesh) return; // Skip update if the bullet has been "killed"

    mesh->position.add(velocity);
    lifespan -= deltaTime;

    // Automatically "kill" the bullet if its lifespan expires
    if (lifespan <= 0) {
        kill();
    }
}

void Bullet::draw(const std::shared_ptr<Scene>& scene) {
    if (mesh) {
        scene->add(mesh);
    }
}

void Bullet::kill( ) {
    if (mesh && mesh->parent) {
        mesh->parent->remove(*mesh); // Remove from the scene
         // Invalidate the mesh pointer
    }
}

bool Bullet::isAlive() const {
    return lifespan > 0 && mesh != nullptr;
}
