#include "line.h"


Line::Line() {
    
}

void Line::generate(int screenWidth, int screenHeight, int thickness, int dashSpacing) {
    const int dashCount = 8;

    for(int i = 0; i < screenHeight / dashCount; i++) {
        sf::RectangleShape shape(sf::Vector2f(thickness, screenHeight / dashCount - dashSpacing));
        shape.setPosition(screenWidth / 2 - thickness / 2, (screenHeight / dashCount) * i);
        this->dashes.push_back(shape);
    }
}



void Line::render(sf::RenderWindow *window, int screenWidth, int screenHeight) {
    for(auto& shape : this->dashes) {
        window->draw(shape);
    }
}