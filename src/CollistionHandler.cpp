#include "CollistionHandler.hpp"
#include "Spaceship.hpp"
#include "Bullet.hpp"
#include "Asteroid.hpp"

CollisionHandler::CollisionHandler(const float bulletRadius, const float asteroidRadius, const float spaceshipRadius, const std::shared_ptr<Scene>& scene)
    : bulletRadius(bulletRadius), asteroidRadius(asteroidRadius), spaceshipRadius(spaceshipRadius), scene(scene) {}

void CollisionHandler::checkCollisions(
    std::vector<std::shared_ptr<Bullet>>& bullets,
    std::vector<std::shared_ptr<Asteroid>>& asteroids,
    const Spaceship& spaceship,
    bool& running,
    int& score) {

    // Check collisions between bullets and asteroids
    for (std::vector<std::shared_ptr<Bullet>>::iterator bullet = bullets.begin(); bullet != bullets.end();) {
        bool bulletHit = false;

        for (auto asteroid = asteroids.begin(); asteroid != asteroids.end();) {
            //This will take away z.Axsis
            float distanceSquared = calculateDistanceSquared2D((*bullet)->getPosition(), (*asteroid)->getPosition());
            float radiusSum = bulletRadius + asteroidRadius;

            if (distanceSquared < (radiusSum * radiusSum)) {
                //Remove Astorid and Bullet, after Bullet hit Astroid
                (*bullet)->kill();
                (*asteroid)->kill();

                // Erase bullet and Astroid from vektor
                bullet = bullets.erase(bullet);
                asteroids.erase(asteroid);
                //update Score
                bulletHit = true;
                score += 10;

                // This will spown 1 new Astroid after hit
                std::shared_ptr<Asteroid>newAsteroid = std::make_shared<Asteroid>(scene);
                asteroids.push_back(newAsteroid);

                break;
            }
                ++asteroid;

        }

        if (!bulletHit) {
            ++bullet;
        }
    }

    // Spaceship collisions with asteroids
    for (const std::shared_ptr<Asteroid>& asteroid : asteroids) {
        float distanceSquared = calculateDistanceSquared2D(spaceship.getPosition(), asteroid->getPosition());
        float radiusSum = spaceshipRadius + asteroidRadius;

        if (distanceSquared < (radiusSum * radiusSum)) {
            running = false;// Game over
            return;
        }
    }
}
