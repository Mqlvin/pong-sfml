#include <algorithm>

#include "player.h"

Player::Player(bool isLeft, int screenWidth, int screenHeight) {
    this->isLeft = isLeft;

    this->pos = sf::Vector2f((isLeft ? 50 : screenWidth - 50), screenHeight / 2 - Player::paddleWidth / 2);
    this->size = sf::Vector2f(Player::paddleHeight, Player::paddleWidth);

    this->component = sf::RectangleShape(this->size);
}

void Player::render(sf::RenderWindow *window) {
    this->component.setPosition(this->pos);
    window->draw(this->component);
}

void Player::handleMovement(bool upPressed, bool downPressed, int screenWidth, int screenHeight) {
    if(upPressed && !downPressed) {
        this->pos.y -= Player::moveSpeed;
    } else if(!upPressed && downPressed) {
        this->pos.y += Player::moveSpeed;
    }

    // clamp bounds
    this->pos.y = std::min(std::max(this->pos.y, 0.f), screenHeight - Player::paddleWidth);
}

sf::Vector2f Player::getPos() {
    return this->pos;
}

sf::Vector2f Player::getSize() {
    return this->size;
}