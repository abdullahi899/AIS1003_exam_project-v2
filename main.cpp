#include "Astroid.hpp"
#include "GameInput.hpp"
#include "Spaceship.hpp"
#include "threepp/threepp.hpp"
#include "Bullet.hpp"



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


    Spaceship spaceship(scene);

    auto astroids = Astroid::generateAstroids(scene, 5);

    GameInput gameInput(spaceship);
    canvas.addKeyListener(gameInput);

    std::vector<std::shared_ptr<Bullet> > bullets;

    canvas.animate([&]() {

        renderer.render(*scene, *camera);
        gameInput.update(bullets);

        for (auto shot = bullets.begin(); shot != bullets.end();) {
            (*shot)->update(0.20f);
            if (!(*shot)->isAlive()) {
                shot = bullets.erase(shot);
            } else {
                (*shot)->draw(scene);
                ++shot;
            }
        }
        for (auto &astroid: astroids) {
            astroid->update();
        }
    });
    return 0;
}
