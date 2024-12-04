#define CATCH_CONFIG_MAIN
#include "Asteroid.hpp"
#include "catch2/catch_test_macros.hpp"
#include "threepp/threepp.hpp"

TEST_CASE(" Astroid scene") {
    using namespace threepp;

    auto scene = Scene::create();

    SECTION("Asteroid is made and added to scene") {
        auto asteroid = std::make_shared<Asteroid>(scene);
        REQUIRE(scene->children.size() == 1);
    }
}