#include "Astroid.hpp"
#include "GameInput.hpp"
#include "Spaceship.hpp"
#include "threepp/threepp.hpp"


using namespace threepp;

int main() {
    // Create the rendering window
    Canvas canvas("Top-Down View of Spaceship", {{"resizable", false}});
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


    // Create ground in threepp
    auto groundGeometry = BoxGeometry::create(100, 1, 0);
    auto groundMaterial = MeshPhongMaterial::create();
    groundMaterial->color = Color::black;
    auto groundMesh = Mesh::create(groundGeometry, groundMaterial);
    groundMesh->position.set(0, -10.0f, -5.0f);
    scene->add(groundMesh);

    Spaceship spaceship(scene);

    GameInput gameInput(spaceship);
    canvas.addKeyListener(gameInput);

    canvas.animate([&]() {
        renderer.render(*scene, *camera);
        gameInput.update();
    });
    return 0;
}