#include "CollistionHandler.hpp"
#include "Spaceship.hpp"
#include "Bullet.hpp"
#include "Astroid.hpp"

CollisionHandler::CollisionHandler(float bulletRadius, float asteroidRadius, float spaceshipRadius, const std::shared_ptr<Scene>& scene)
    : bulletRadius(bulletRadius), asteroidRadius(asteroidRadius), spaceshipRadius(spaceshipRadius), scene(scene) {}

void CollisionHandler::checkCollisions(
    std::vector<std::shared_ptr<Bullet>>& bullets,
    std::vector<std::shared_ptr<Astroid>>& astroids,
    const Spaceship& spaceship,
    bool& running,
    int& score) {

    // Check collisions between bullets and asteroids
    for (std::vector<std::shared_ptr<Bullet>>::iterator bullet = bullets.begin(); bullet != bullets.end();) {
        bool bulletHit = false;

        for (auto asteroid = astroids.begin(); asteroid != astroids.end();) {
            //This will take away z.Axsis
            float distanceSquared = calculateDistanceSquared2D((*bullet)->getPosition(), (*asteroid)->getPosition());
            float radiusSum = bulletRadius + asteroidRadius;

            if (distanceSquared < (radiusSum * radiusSum)) {
                //Remove Astorid and Bullet, after Bullet hit Astroid
                (*bullet)->kill();
                (*asteroid)->kill();

                // Erase bullet and Astroid from vektor
                bullet = bullets.erase(bullet);
                asteroid = astroids.erase(asteroid);
                //update Score
                bulletHit = true;
                score += 10;

                // This will spown 1 new Astroid
                std::shared_ptr<Astroid>newAsteroid = std::make_shared<Astroid>(scene);
                astroids.push_back(newAsteroid);

                break;
            }
                ++asteroid;

        }

        if (!bulletHit) {
            ++bullet;
        }
    }

    // Spaceship collisions with asteroids
    for (const std::shared_ptr<Astroid>& asteroid : astroids) {
        float distanceSquared = calculateDistanceSquared2D(spaceship.getPosition(), asteroid->getPosition());
        float radiusSum = spaceshipRadius + asteroidRadius;

        if (distanceSquared < (radiusSum * radiusSum)) {
            running = false;// Game over
            return;
        }
    }
}
