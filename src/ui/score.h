#pragma once

#include <SFML/Graphics.hpp>
#include <string>
#include <cmath>
#include <iostream>

class Score {
    public:
        Score();
        void render(sf::RenderWindow *window, bool isLeftPlayer, int score, int screenWidth, int screenHeight);
        void calcColor(long ticks, long ticksSinceLastGoal, bool scoringNumber);

    private:
        sf::Font font;
        sf::Color color;
};