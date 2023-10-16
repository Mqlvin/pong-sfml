#include <SFML/Graphics.hpp>
#include <cmath>
#include <iostream>

#include "./player/player.h"
#include "./ball/ball.h"
#include "./ui/line.h"
#include "./ui/score.h"

int main()
{
    sf::ContextSettings settings;
    settings.antialiasingLevel = 8.0;

    sf::RenderWindow window(sf::VideoMode(800, 800), "SFML", sf::Style::Close, settings);

    window.setFramerateLimit(60);

    long ticks = 0;
    bool windowFocused = true;
    bool gameStarted = false;
    bool lastScoreWasLeft = false;
    long ticksSinceLastGoal = 30;

    Player p1(true, 800, 800);
    Score p1_s;
    int p1_si = 0;
    Player p2(false, 800, 800);
    Score p2_s;
    int p2_si = 0;

    Ball ball(false, 800, 800);
    Line line;
    line.generate(800, 800, 8, 60);

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if(event.type == sf::Event::Closed) window.close();
            else if(event.type == sf::Event::GainedFocus) windowFocused = true;
            else if(event.type == sf::Event::LostFocus) windowFocused = false;
            else if(event.type == sf::Event::KeyPressed) gameStarted = true;
        }

        if(!windowFocused) continue;

        if(gameStarted) {
            p1.handleMovement(sf::Keyboard::isKeyPressed(sf::Keyboard::W), sf::Keyboard::isKeyPressed(sf::Keyboard::S), 800, 800);
            p2.handleMovement(sf::Keyboard::isKeyPressed(sf::Keyboard::Up), sf::Keyboard::isKeyPressed(sf::Keyboard::Down), 800, 800);
            ball.handleMovement(800, 800);

            if(ball.isTouchingRoof(800, 800)) {
                ball.bounceOffRoof();
            }
            if(ball.isTouchingPaddle(p1.getPos(), p1.getSize())) {
                ball.bounceOffPaddle(p1.getPos(), p1.getSize(), true);
            }
            if(ball.isTouchingPaddle(p2.getPos(), p2.getSize())) {
                ball.bounceOffPaddle(p2.getPos(), p2.getSize(), false);
            }

            if(ball.isOffScreen(800, 800)) {
                lastScoreWasLeft = !ball.isOffLeftSide(800, 800);
                if(lastScoreWasLeft) p1_si++;
                else p2_si++;

                ticksSinceLastGoal = 0;

                ball.reset(800, 800, lastScoreWasLeft);
            }



            p1_s.calcColor(ticks, ticksSinceLastGoal, lastScoreWasLeft);
            p2_s.calcColor(ticks, ticksSinceLastGoal, !lastScoreWasLeft);

            ticks++;
            ticksSinceLastGoal++;
        }
        
        


        window.clear();

        line.render(&window, 800, 800);
        if(gameStarted) {
            p1_s.render(&window, true, p1_si, 800, 800);
            p2_s.render(&window, false, p2_si, 800, 800);
        }

        p1.render(&window);
        p2.render(&window);
        ball.render(&window);


        window.display();
    }

    return 0;
}
