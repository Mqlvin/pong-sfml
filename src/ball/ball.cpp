#include <cmath>
#include <iostream>

#include "ball.h"

Ball::Ball(bool startMoveLeft, int screenWidth, int screenHeight) {
    this->nextDirectionLeft = startMoveLeft;
    this->pos = sf::Vector2f(screenWidth / 2, screenHeight / 2);
    this->vel = sf::Vector2f(this->speed/2, 0);

    this->component = sf::CircleShape(this->radius, 20);
    this->component.setOrigin(this->radius, this->radius);
}

void Ball::render(sf::RenderWindow *window) {
    this->component.setPosition(this->pos);
    window->draw(this->component);
}

void Ball::handleMovement(int screenWidth, int screenHeight) {
    this->pos += this->vel;
}



bool Ball::isOffScreen(int screenWidth, int screenHeight) {
    return (this->radius > this->pos.x) || (this->pos.x > screenHeight - this->radius);
}

bool Ball::isOffLeftSide(int screenWidth, int screenHeight) {
    return this->pos.x < screenWidth / 2;
}

void Ball::reset(int screenWidth, int screenHeight, bool leftScored) {
    this->pos = sf::Vector2f(screenWidth / 2, screenHeight / 2);
    this->vel = sf::Vector2f(this->speed/2 * (leftScored ? 1 : -1), 0);
}



bool Ball::isTouchingPaddle(sf::Vector2f paddlePos, sf::Vector2f paddleSize) {
    return paddlePos.x + paddleSize.x + this->radius > this->pos.x && paddlePos.x - this->radius < this->pos.x && // x math
           (paddlePos.y - this->radius < this->pos.y && paddlePos.y + paddleSize.y + this->radius > this->pos.y); // within y bounds
    // math diagrams in excalidraw/obsidian
}

void Ball::bounceOffPaddle(sf::Vector2f paddlePos, sf::Vector2f paddleSize, bool wasLeftPaddle) {
    float maxAngleMod = this->maxAngle * (((this->pos.y - paddlePos.y) / (paddleSize.y) * 2) - 1);
    float modRadian = maxAngleMod * (3.1415f / 180.f);
    // std::cout << maxAngleMod << std::endl;
    
    this->vel.x = std::cos(modRadian) * this->speed;
    this->vel.y = std::sin(modRadian) * this->speed;

    // if hitting the right paddle, reverse numbers
    if(!wasLeftPaddle) {
        this->vel.x *= -1;
    }
}



bool Ball::isTouchingRoof(int screenWidth, int screenHeight) {
    return this->radius > this->pos.y || screenHeight - this->radius < this->pos.y;
}

void Ball::bounceOffRoof() {
    this->vel.y *= -1;
    // if(this->pos.y < 50) this->pos.y += 1;
    // else this->pos.y -= 1;
}
