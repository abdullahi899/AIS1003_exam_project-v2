#ifndef GAMEINPUT_HPP
#define GAMEINPUT_HPP

#include "Spaceship.hpp"
#include <threepp/threepp.hpp>
#include "Bullet.hpp"

using namespace threepp;

class GameInput : public threepp::KeyListener {
public:
    explicit GameInput(Spaceship &spaceship) : m_spaceship(spaceship) {
    }


    void update(std::vector<std::shared_ptr<Bullet> > &bullets) {
        if (moveUp) {
            m_spaceship.moveUp();
        }
        if (moveLeft) {
            m_spaceship.moveLeft();
        }
        if (moveRight) {
            m_spaceship.moveRight();
        }

        if (shoot and !shoot_0) {
            m_spaceship.shoot(bullets);
        }
        shoot_0 = shoot;
    }

private:
    bool moveUp = false;
    bool moveDown = false;
    bool moveLeft = false;
    bool moveRight = false;
    bool shoot = false;
    bool shoot_0 = false;


    void onKeyPressed(threepp::KeyEvent evt) override {
        switch (evt.key) {
            case threepp::Key::W:
                moveUp = true;
                break;
            case threepp::Key::S:
                moveDown = true;
                break;
            case threepp::Key::A:
                moveLeft = true;
                break;
            case threepp::Key::D:
                moveRight = true;
                break;
            case threepp::Key::SPACE:
                shoot = true;
                break;
            default:
                break;
        }
    }

    void onKeyReleased(threepp::KeyEvent evt) override {
        switch (evt.key) {
            case threepp::Key::W:
                moveUp = false;
                break;
            case threepp::Key::S:
                moveDown = false;
                break;
            case threepp::Key::A:
                moveLeft = false;
                break;
            case threepp::Key::D:
                moveRight = false;
                break;
            case threepp::Key::SPACE:
                shoot = false;
                break;
            default:
                break;
        }
    }


    Spaceship &m_spaceship;
};

#endif// GAMEINPUT_HPP
