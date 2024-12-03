#include <imgui.h>
#include "Spaceship.hpp"
#include "Astroid.hpp"
#include "Bullet.hpp"
#include "GameInput.hpp"
#include "Collison helper.hpp"
#include "Imugi.hpp"
#include "threepp/threepp.hpp"
#include <memory>
#include <vector>

using namespace threepp;

int main() {
    // Initialize Threepp canvas and renderer
    Canvas canvas("Astroid-Game", {{"resizable", false}});
    canvas.setSize({1000, 1000});
    GLRenderer renderer(canvas.size());
    renderer.setClearColor(Color::white);

    // Create ImGui helper
    ImGuiHelper imguiHelper(reinterpret_cast<GLFWwindow*>(canvas.windowPtr()));

    // Scene and camera setup
    auto scene = Scene::create();
    auto camera = OrthographicCamera::create(-10, 10, 10, -10, -100.0f, 100.0f);
    camera->position.set(0, 0, 0);
    camera->lookAt(Vector3(0, 0, 0));

    // Initialize game objects
    Spaceship spaceship(scene);
    auto astroids = Astroid::generateAstroids(scene, 7);
    std::vector<std::shared_ptr<Bullet>> bullets;

    // Input and collision handling
    GameInput gameInput(spaceship);
    canvas.addKeyListener(gameInput);
    CollisionHandler collisionHandler(0.2f, 0.5f, 0.3f, scene);

    // Game state
    int score = 0;
    bool running = true;

    // Main game loop
    canvas.animate([&]() {
        if (!running) return; // Stop the game if not running

        // Clear the screen and render the scene
        renderer.render(*scene, *camera);

        // Start ImGui frame
        imguiHelper.beginFrame();

        // Update game logic
        gameInput.update(bullets); // Handle input
        spaceship.update(0.0083333333333333f); // Update spaceship
        for (auto& bullet : bullets) bullet->update(0.0083333333333333f);
        for (auto& astroid : astroids) astroid->update(0.0083333333333333f);

        // Collision handling
        collisionHandler.checkCollisions(bullets, astroids, spaceship, running, score);


        // Draw bullets
        for (auto& bullet : bullets) bullet->draw(scene);

        // Add ImGui components
        ImGui::Begin("Scoreboard");
        ImGui::Text("Score: %d", score);
        ImGui::End();

        // Render ImGui components
        imguiHelper.render();
    });

    return 0;
}
