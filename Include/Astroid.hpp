#ifndef ASTROID_HPP
#define ASTROID_HPP

#include "Conector.hpp"
#include <vector>
#include <memory>

class Astroid : public GameObject {
public:
    void kill(){

}

    explicit Astroid(const std::shared_ptr<threepp::Scene> &scene);

    void update(float deltaTime) override;

    void draw(const std::shared_ptr<threepp::Scene> &scene) override;

    static std::vector<std::shared_ptr<Astroid> > generateAstroids(
        const std::shared_ptr<threepp::Scene> &scene, int count);

private:
    threepp::Vector3 velocity;
};

#endif // ASTROID_HPP
