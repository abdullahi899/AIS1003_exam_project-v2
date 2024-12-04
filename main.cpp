#include "Spaceship.hpp"
#include "Asteroid.hpp"
#include "Bullet.hpp"
#include "GameInput.hpp"
#include "CollistionHandler.hpp"
#include "Imgui.hpp"
#include "threepp/threepp.hpp"

using namespace threepp;

int main() {
    //this will make the screen
    Canvas canvas("Astroid-Game", {{"resizable", false}});
    canvas.setSize({1000, 1000});
    GLRenderer renderer(canvas.size());
    renderer.setClearColor(Color::white);

    // It will create ImguiHelper
    ImGuiHelper imguiHelper(static_cast<GLFWwindow *>(canvas.windowPtr()));

    // Camera and scene
    const auto scene = Scene::create();
    const auto camera = OrthographicCamera::create(-10, 10, 10, -10, -100.0f, 100.0f);
    camera->position.set(0, 0, 0);

    // This will create Astroid
    Spaceship spaceship(scene);
    auto astroids = Asteroid::generateAsteroid(scene, 7);
    std::vector<std::shared_ptr<Bullet> > bullets;


    //this is keyinput
    GameInput gameInput(spaceship);
    canvas.addKeyListener(gameInput);

    // it will handle the radi of Bullet, Astroid, Spaceship and add this to the scene
    CollisionHandler collisionHandler(0.1f, 0.5f, 0.3f, scene);

    // game score will start at 0
    int score = 0;
    bool running = true;

    // Main game loop
    canvas.animate([&]() {
        //this will stop the game if Astroid hit Spaceship
        if (!running) {
            return;
        };

        // it will clear the screen and render the scene
        renderer.render(*scene, *camera);

        // will make the imugi frame
        imguiHelper.beginFrame();

        // Update game logic
        gameInput.update(bullets);


        // this will make the game 60 frames per/s
        spaceship.update(0.0166666666666667f);
        for (auto &bullet: bullets) bullet->update(0.0166666666666667f);
        for (auto &astroid: astroids) astroid->update(0.0166666666666667f);

        // Collision handling
        collisionHandler.checkCollisions(bullets, astroids, spaceship, running, score);


        // Draw bullets
        for (const auto &bullet: bullets) bullet->draw(scene);

        // will Add ImGui components
        ImGui::Begin("Scoreboard");
        ImGui::Text("Score: %d", score);
        ImGui::End();

        // this will oppdate the imgui
        imguiHelper.render();
    });

    return 0;
}
