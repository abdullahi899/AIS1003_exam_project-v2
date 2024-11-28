#include "Astroid.hpp"
#include "GameInput.hpp"
#include "Spaceship.hpp"
#include "threepp/threepp.hpp"
#include "Bullet.hpp"


using namespace threepp;

int main() {
    // Create the rendering window
    Canvas canvas("Astroid-Game", {{"resizable", false}});
    canvas.setSize({800, 800});
    GLRenderer renderer(canvas.size());
    renderer.setClearColor(Color::white);

    // Create the scene and camera
    auto scene = Scene::create();

    auto camera = OrthographicCamera::create(
            -10, 10,
            10, -10,
            -100.0f, 100.0f);

    camera->position.set(0, 5, 0);// Position the camera above the spaceship
    camera->lookAt(Vector3(0, 0, 0));


    Spaceship spaceship(scene);

    auto astroids = Astroid::generateAstroids(scene, 10);


    /*std::vector<std::shared_ptr<Bullet>> bullets;*/


    GameInput gameInput(spaceship);
    canvas.addKeyListener(gameInput);


    canvas.animate([&]() {
        renderer.render(*scene, *camera);
        gameInput.update();
        for (auto &astroid : astroids) {
       astroid->update();
   }

    });
    return 0;
}