#include "Spaceship.hpp"
#include "Astroid.hpp"
#include "Bullet.hpp"
#include "GameInput.hpp"
#include "Collison helper.hpp"
#include "threepp/threepp.hpp"
#include "imgui.h"
#include "imgui_impl_glfw.h"
#include "imgui_impl_opengl3.h"
#include <memory>
#include <vector>

using namespace threepp;

int main() {
    // Initialize threepp canvas and renderer
    Canvas canvas("Asteroid Game");
    canvas.setSize({1000, 1000});
    GLRenderer renderer(canvas.size());
    renderer.setClearColor(Color::white);

    // Initialize ImGui
    ImGui::CreateContext();
    ImGuiIO &io = ImGui::GetIO();
    ImGui_ImplGlfw_InitForOpenGL(reinterpret_cast<GLFWwindow *>(canvas.windowPtr()), true);
    ImGui_ImplOpenGL3_Init("#version 130");

    // Scene and camera setup
    auto scene = Scene::create();
    auto camera = OrthographicCamera::create(-10, 10, 10, -10, -100.0f, 100.0f);
    camera->position.set(0, 0, 0); // Camera at origin
    camera->lookAt(Vector3(0, 0, 0)); // Look forward along the -Z axis

    // Initialize game objects
    Spaceship spaceship(scene);
    auto astroids = Astroid::generateAstroids(scene, 1);
    std::vector<std::shared_ptr<Bullet> > bullets;

    // Input and collision handling
    GameInput gameInput(spaceship);
    canvas.addKeyListener(gameInput);
    // Input and collision handling
    CollisionHandler collisionHandler(0.2f, 0.5f, 0.3f, scene); // Pass the scene as the fourth argument


    // Game state
    int score = 0;
    bool running = true;

    // Main game loop
    canvas.animate([&]() {
        if (!running) return; // Stop the game if not running

        renderer.render(*scene, *camera);

        // ImGui new frame
        ImGui_ImplOpenGL3_NewFrame();
        ImGui_ImplGlfw_NewFrame();
        ImGui::NewFrame();

        // Update game logic
        gameInput.update(bullets); // Handle input
        spaceship.update(0.0083333333333333f); // Update spaceship
        for (auto &bullet: bullets) bullet->update(0.0083333333333333f);
        for (auto &astroid: astroids) astroid->update(0.0083333333333333f);

        // Collision handling
        collisionHandler.checkCollisions(bullets, astroids, spaceship, running, score);

        // Draw bullets
        for (auto &bullet: bullets) bullet->draw(scene);

        // ImGui score display
        ImGui::Begin("Scoreboard");
        ImGui::Text("Score: %d", score); // Show current score
        ImGui::End();

        // Render ImGui
        ImGui::Render();
        ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());
    });

    // Cleanup ImGui
    ImGui_ImplOpenGL3_Shutdown();
    ImGui_ImplGlfw_Shutdown();
    ImGui::DestroyContext();

    return 0;
}
