#include "Bullet.hpp"

using namespace threepp;

Bullet::Bullet(const Vector3 &position, const Vector3 &direction, const float speed, const float lifespan)
    : velocity(direction * speed), lifespan(lifespan) {
    //Bullet will be made her
    const std::shared_ptr<SphereGeometry> geometry = SphereGeometry::create(0.2f, 16, 16);
    const std::shared_ptr<MeshBasicMaterial> material = MeshBasicMaterial::create();
    material->color = Color::red;
    mesh = Mesh::create(geometry, material);
    mesh->position.copy(position);
}

void Bullet::update(const float deltaTime) {

    //Bullet will move
    mesh->position.add(velocity);

    //How long the bullet will exsist
    lifespan -= deltaTime;

    // Automatically "kill" the bullet if its lifespan expires
    if (lifespan <= 0) {
        kill();
    }
}

void Bullet::draw(const std::shared_ptr<Scene> &scene) {
    //Bullet will be added to the scene
    if (mesh) {
        scene->add(mesh);
    }
}

void Bullet::kill() {
    if (mesh && mesh->parent) {
        //Bullet will be removed from scene
        mesh->parent->remove(*mesh);

    }
}

