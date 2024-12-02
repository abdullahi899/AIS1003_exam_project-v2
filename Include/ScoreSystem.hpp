#ifndef SCORESYSTEM_HPP
#define SCORESYSTEM_HPP

#include <memory>
#include "threepp/threepp.hpp"

class ScoreSystem {
public:
    explicit ScoreSystem(const std::shared_ptr<threepp::Canvas>& canvas);

    void addPoints(int points);
    void resetScore();
    void updateDisplay();

private:
    int score_;
    std::shared_ptr<threepp::Canvas> canvas_;
    std::shared_ptr<threepp::Text3D> text_;
};

#endif // SCORESYSTEM_HPP
