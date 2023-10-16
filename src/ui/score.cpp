#include "score.h"

Score::Score() {
    this->font.loadFromFile("./bit5x3.ttf");
}

void Score::render(sf::RenderWindow *window, bool isLeftPlayer, int score, int screenWidth, int screenHeight) {
    sf::Text text(std::to_string(score), this->font);
    text.setCharacterSize(50);
    text.setFillColor(this->color);
    text.setOrigin(std::floor(text.getLocalBounds().left + text.getLocalBounds().width / 2.f), std::floor(text.getLocalBounds().top + text.getLocalBounds().height / 2.f));
    text.setPosition(sf::Vector2f(screenWidth / 4 * (isLeftPlayer ? 1 : 3), 50));

    window->draw(text);
}

// "scoringNumber" denotes whether that score object is correlates to the team scored
void Score::calcColor(long ticks, long ticksSinceLastGoal, bool scoringNumber) {
    if(ticksSinceLastGoal < 30 && scoringNumber) {\
        float rb = 255 - std::floor(std::sin((ticksSinceLastGoal + 1) * (3.1415f / 30.f)) * 55.f);
        this->color = sf::Color(rb, 255.f, rb);
    } else if(ticks < 30) {
        float val = std::floor((ticks / 30.f) * 255.f);
        this->color = sf::Color(val, val, val);
    }
}