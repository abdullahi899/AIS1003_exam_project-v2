#include "Astroid.hpp"
#include "GameInput.hpp"
#include "Spaceship.hpp"
#include "Bullet.hpp"
#include "threepp/threepp.hpp"
#include <algorithm>
#include <iostream>

using namespace threepp;

int main() {

    Canvas canvas("Astroid-Game", {{"resizable", false}});
    canvas.setSize({1000, 1000});
    GLRenderer renderer(canvas.size());
    renderer.setClearColor(Color::white);

    auto scene = Scene::create();

    auto camera = OrthographicCamera::create(
        -10, 10,
        10, -10,
        -100.0f, 100.0f);

    camera->position.set(0, 5, 0);
    camera->lookAt(Vector3(0, 0, 0));

    // Create game objects
    Spaceship spaceship(scene);
    auto astroids = Astroid::generateAstroids(scene, 5);
    GameInput gameInput(spaceship);
    canvas.addKeyListener(gameInput);

    std::vector<std::shared_ptr<Bullet>> bullets;
    bool running = true; // Flag to control the game loop

    // Define radii for collision detection
    const float bulletRadius = 0.2f;
    const float asteroidRadius = 0.5f;
    const float spaceshipRadius = 0.3f;

    // Animation loop
    canvas.animate([&]() {
        if (!running) return; // Stop rendering if the game is over

        renderer.render(*scene, *camera);
        gameInput.update(bullets);

        // Update and clean up bullets
        for (auto shot = bullets.begin(); shot != bullets.end();) {
            (*shot)->update(0.20f);
            if (!(*shot)->isAlive()) {
                shot = bullets.erase(shot);
            } else {
                (*shot)->draw(scene);
                ++shot;
            }
        }

        // Update asteroids
        for (auto &astroid : astroids) {
            astroid->update();
        }

        // Collision detection: Bullet vs. Asteroid
        for (auto bullet = bullets.begin(); bullet != bullets.end();) {
            bool bulletHit = false;

            for (auto astroid = astroids.begin(); astroid != astroids.end();) {
                float distance = (*bullet)->getPosition().distanceTo((*astroid)->getPosition());
                if (distance < (bulletRadius + asteroidRadius)) { // Collision threshold
                    std::cout << "Bullet hit an asteroid!" << std::endl; // Terminal message
                    bullet = bullets.erase(bullet); // Remove bullet
                    astroid = astroids.erase(astroid); // Remove asteroid
                    bulletHit = true;
                    break;
                } else {
                    ++astroid;
                }
            }

            if (!bulletHit) {
                ++bullet;
            }
        }

        // Collision detection: Spaceship vs. Asteroid
        for (const auto &astroid : astroids) {
            float distance = spaceship.getPosition().distanceTo(astroid->getPosition());
            if (distance < (spaceshipRadius + asteroidRadius)) { // Collision threshold
                std::cout << "Game Over! Spaceship hit an asteroid." << std::endl;
                running = false; // Stop the game
                return;
            }
        }
    });

    return 0;
}
