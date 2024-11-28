#ifndef ASTROID_HPP
#define ASTROID_HPP

#include "threepp/threepp.hpp"
#include <memory>
#include <vector>

class Astroid {
public:
    explicit Astroid(std::shared_ptr<threepp::Scene> scene);

    void update();
    static std::vector<std::shared_ptr<Astroid>> generateAstroids(
        std::shared_ptr<threepp::Scene> scene, int count);



private:
    std::shared_ptr<threepp::Mesh> mesh;
    threepp::Vector3 velocity;


};

#endif // ASTROID_HPP
