#include <catch2/catch_test_macros.hpp>
#include "Spaceship.hpp"
#include "threepp/threepp.hpp"

TEST_CASE("Spaceship Movement") {
    auto scene = threepp::Scene::create();
    Spaceship spaceship(scene);

    SECTION("Initial Position") {
        auto position = spaceship.getPosition();
        REQUIRE(position.x == Approx(0.0f).margin(0.01f));
        REQUIRE(position.y == Approx(0.0f).margin(0.01f));
    }

    SECTION("Move Up") {
        spaceship.moveUp();
        auto position = spaceship.getPosition();
        REQUIRE(position.y > Approx(0.0f).margin(0.01f));
    }

    SECTION("Move Left") {
        spaceship.moveLeft();
        auto rotation = spaceship.mesh->rotation.y; // Assuming moveLeft modifies rotation
        REQUIRE(rotation > 0.0f);
    }
}
