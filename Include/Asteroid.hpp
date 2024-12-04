#ifndef ASTEROID_HPP
#define ASTEROID_HPP

#include "GameObject.hpp"
#include "threepp/threepp.hpp"
#include <vector>
#include <memory>

class Asteroid final : public GameObject {
public:
    explicit Asteroid(const std::shared_ptr<threepp::Scene>& scene);

    void update(float deltaTime) override;
    void draw(const std::shared_ptr<threepp::Scene>& scene) override;
    void kill() override;

    static std::vector<std::shared_ptr<Asteroid>> generateAsteroid(
        const std::shared_ptr<threepp::Scene>& scene, int count);

private:
    threepp::Vector3 velocity;
};

#endif // ASTEROID_HPP