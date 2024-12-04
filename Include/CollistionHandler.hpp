#ifndef COLLLISTIONHANDLER_HPP
#define COLLLISTIONHANDLER_HPP

#include <vector>
#include <memory>
#include <Spaceship.hpp>
#include "Asteroid.hpp"
#include "Bullet.hpp"
#include "threepp/math/Vector3.hpp"


using namespace threepp;

class CollisionHandler {
public:
    CollisionHandler(float bulletRadius, float asteroidRadius, float spaceshipRadius, const std::shared_ptr<threepp::Scene>& scene);

    void checkCollisions(
        std::vector<std::shared_ptr<Bullet>>& bullets,
        std::vector<std::shared_ptr<Asteroid>>& asteroids,
        const Spaceship& spaceship,
        bool& running,
        int& score);

private:
    float bulletRadius;
    float asteroidRadius;
    float spaceshipRadius;

    std::shared_ptr<Scene> scene;

     static float calculateDistanceSquared2D(const Vector3& xAxis, const Vector3& yAxis) {
         const float dx =xAxis.x - yAxis.x;
         const float dy = xAxis.y - yAxis.y;
        return dx * dx + dy * dy;
    }
};

#endif
