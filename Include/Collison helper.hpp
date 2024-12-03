#ifndef COLLISION_HELPER_HPP
#define COLLISION_HELPER_HPP

#include <vector>
#include <memory>
#include "threepp/math/Vector3.hpp"

class Spaceship;
class Bullet;
class Astroid;
namespace threepp
{class Scene;}

class CollisionHandler {
public:
    CollisionHandler(float bulletRadius, float asteroidRadius, float spaceshipRadius, const std::shared_ptr<threepp::Scene>& scene);

    void checkCollisions(
        std::vector<std::shared_ptr<Bullet>>& bullets,
        std::vector<std::shared_ptr<Astroid>>& astroids,
        const Spaceship& spaceship,
        bool& running,
        int& score);

private:
    float bulletRadius;
    float asteroidRadius;
    float spaceshipRadius;

    std::shared_ptr<threepp::Scene> scene;

     float calculateDistanceSquared2D(const threepp::Vector3& abd, const threepp::Vector3& b) {
        float dx = abd.x - b.x;
        float dy = abd.y - b.y;
        return dx * dx + dy * dy;
    }
};

#endif // COLLISION_HELPER_HPP
