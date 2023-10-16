#pragma once

#include <vector>
#include <SFML/Graphics.hpp>

class Line {
    public:
        Line();
        void generate(int screenWidth, int screenHeight, int thickness, int dashSpacing);
        void render(sf::RenderWindow *window, int screenWidth, int screenHeight);

    private:
        std::vector<sf::RectangleShape> dashes;
};