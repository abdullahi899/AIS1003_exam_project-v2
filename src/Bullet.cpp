#include "Bullet.hpp"
#include "threepp/threepp.hpp"



using namespace threepp;

Bullet::Bullet(const Vector3 &position, const Vector3 &direction, float speed, float lifespan)
    : velocity(direction * speed), lifespan(lifespan) {

    auto geometry = SphereGeometry::create(0.20f, 16, 16);
    auto material = MeshBasicMaterial::create();
    material->color = Color::red;

    mesh = Mesh::create(geometry, material);
    mesh->position.copy(position);
}

void Bullet::update(float) {

    mesh->position.add(velocity );


}

bool Bullet::isAlive() const {
    return lifespan > 0;
}

void Bullet::draw(const std::shared_ptr<Scene> &scene) {
        scene->add(mesh);
    }


const Vector3 &Bullet::getPosition() const {
    return mesh->position;
}
