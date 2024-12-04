#define CATCH_CONFIG_MAIN
#include "Bullet.hpp"
#include "catch2/catch_approx.hpp"
#include "catch2/catch_test_macros.hpp"
#include "threepp/threepp.hpp"

TEST_CASE("Bullet updates its position") {
    using namespace threepp;

    Bullet bullet(Vector3(0, 0, 0), Vector3(0.1f, 0, 0), 0.1f, 5.0f);

    bullet.update(0.1f);

    REQUIRE(bullet.getPosition().x == Catch::Approx(0.01f).margin(0.001f));
    REQUIRE(bullet.getPosition().y == Catch::Approx(0.0f));
    REQUIRE(bullet.getPosition().z == Catch::Approx(0.0f));
}
