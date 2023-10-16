#pragma once

#include <SFML/Graphics.hpp>

class Player {
    public:
        void handleMovement(bool upPressed, bool downPressed, int screenWidth, int screenHeight);
        void render(sf::RenderWindow *window);
        Player(bool isLeft, int screenWidth, int screenHeight);

        sf::Vector2f getPos();
        sf::Vector2f getSize();
        sf::RectangleShape component;

    private:
        sf::Vector2f pos;
        sf::Vector2f size;
        bool isLeft;
        static const int moveSpeed = 7;
        static constexpr float paddleWidth = 140.f;
        static constexpr float paddleHeight = 10.f;
};