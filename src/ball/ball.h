#pragma once

#include <SFML/Graphics.hpp>

class Ball {
    public:
        Ball(bool startMoveLeft, int screenWidth, int screenHeight);
        void handleMovement(int screenWidth, int screenHeight);
        void render(sf::RenderWindow *window);
        bool isOffScreen(int screenWidth, int screenHeight);
        bool isOffLeftSide(int screenWidth, int screenHeight);
        void reset(int screenWidth, int screenHeight, bool leftScored);
        bool isTouchingPaddle(sf::Vector2f paddlePos, sf::Vector2f paddleSize);
        void bounceOffPaddle(sf::Vector2f paddlePos, sf::Vector2f paddleSize, bool wasLeftPaddle);
        bool isTouchingRoof(int screenWidth, int screenHeight);
        void bounceOffRoof();

    private:
        sf::Vector2f pos;
        sf::Vector2f vel;
        bool nextDirectionLeft = true;
        sf::CircleShape component;

        static const int speed = 10;
        static const int radius = 8;
        static const int maxAngle = 30;
};