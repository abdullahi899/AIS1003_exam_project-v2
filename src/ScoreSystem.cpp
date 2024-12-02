#include "ScoreSystem.hpp"

using namespace threepp;

ScoreSystem::ScoreSystem(const std::shared_ptr<Canvas>& canvas)
    : score_(0), canvas_(canvas) {

    // Create a text element for the score display
    text_ = Text::create("Score: 0");
    text_->setFont("Arial");
    text_->setFontSize(24);
    text_->setColor(Color::black);
    text_->position.set(10, canvas_->size().height - 30); // Position in the top-left corner
    canvas_->addOverlay(text_);
}

void ScoreSystem::addPoints(int points) {
    score_ += points;
    updateDisplay();
}

void ScoreSystem::resetScore() {
    score_ = 0;
    updateDisplay();
}

void ScoreSystem::updateDisplay() {
    text_->setText("Score: " + std::to_string(score_));
}
