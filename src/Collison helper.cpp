#include "Collison helper.hpp"
#include "Spaceship.hpp"
#include "Bullet.hpp"
#include "Astroid.hpp"

CollisionHandler::CollisionHandler(float bulletRadius, float asteroidRadius, float spaceshipRadius, const std::shared_ptr<threepp::Scene>& scene)
    : bulletRadius(bulletRadius), asteroidRadius(asteroidRadius), spaceshipRadius(spaceshipRadius), scene(scene) {}

void CollisionHandler::checkCollisions(
    std::vector<std::shared_ptr<Bullet>>& bullets,
    std::vector<std::shared_ptr<Astroid>>& astroids,
    const Spaceship& spaceship,
    bool& running,
    int& score) {

    // Check collisions between bullets and asteroids
    for (auto bullet = bullets.begin(); bullet != bullets.end();) {
        bool bulletHit = false;

        for (auto asteroid = astroids.begin(); asteroid != astroids.end();) {
            float distanceSquared = calculateDistanceSquared2D((*bullet)->getPosition(), (*asteroid)->getPosition());
            float radiusSum = bulletRadius + asteroidRadius;

            if (distanceSquared < (radiusSum * radiusSum)) {
                (*bullet)->kill(); // Remove bullet from the scene
                (*asteroid)->kill(); // Remove asteroid from the scene

                bullet = bullets.erase(bullet); // Erase bullet from vector
                asteroid = astroids.erase(asteroid); // Erase asteroid from vector

                bulletHit = true;
                score += 10; // Increment score

                // Optionally, spawn a new asteroid
                auto newAsteroid = std::make_shared<Astroid>(scene);
                astroids.push_back(newAsteroid);

                break; // Exit the inner loop
            } else {
                ++asteroid;
            }
        }

        if (!bulletHit) {
            ++bullet;
        }
    }

    // Check for spaceship collisions with asteroids
    for (const auto& asteroid : astroids) {
        float distanceSquared = calculateDistanceSquared2D(spaceship.getPosition(), asteroid->getPosition());
        float radiusSum = spaceshipRadius + asteroidRadius;

        if (distanceSquared < (radiusSum * radiusSum)) {
            running = false; // Game over
            return;
        }
    }
}
