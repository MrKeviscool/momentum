#include <SFML/Graphics.hpp>
#include <vector>
#include <stdbool.h>

std::vector<sf::RectangleShape *> objects;
std::vector<bool> hurts;
sf::RectangleShape *finish_line = new sf::RectangleShape();
void loadlevel(int level)
{
    finish_line->setFillColor(sf::Color::Green);
    if (level == 1)
    {
        sf::RectangleShape *Floor = new sf::RectangleShape();
        sf::RectangleShape *rightwall = new sf::RectangleShape();
        sf::RectangleShape *leftwall = new sf::RectangleShape();
        sf::RectangleShape *obj1 = new sf::RectangleShape();

        finish_line->setSize(sf::Vector2f( 75, 75));
        finish_line->setPosition(500, 925);
        Floor->setSize(sf::Vector2f(2500, 80));
        Floor->setFillColor(sf::Color::Magenta);
        Floor->setPosition(-500, 1000);

        rightwall->setSize((sf::Vector2f(200, 1080)));
        rightwall->setPosition(1920 - 300, 0);
        rightwall->setFillColor(sf::Color::Magenta);

        leftwall->setSize(sf::Vector2f(50, 300));
        leftwall->setPosition(-500, 700);

        obj1->setSize(sf::Vector2f(500, 50));
        obj1->setPosition(650, 800);
        objects = {Floor, obj1, leftwall, rightwall};
        hurts = {false,false,false,false};
    }
    else if(level == 2){
        sf::RectangleShape *Floor = new sf::RectangleShape();
        sf::RectangleShape *rightwall = new sf::RectangleShape();
        sf::RectangleShape *leftwall = new sf::RectangleShape();
        sf::RectangleShape *obj1 = new sf::RectangleShape();
        finish_line->setSize(sf::Vector2f( 75, 75));
        finish_line->setPosition(500, 925);
        Floor->setSize(sf::Vector2f(2500, 20));
        Floor->setFillColor(sf::Color::Green);
        Floor->setPosition(-500, 1000);

        rightwall->setSize((sf::Vector2f(200, 1080)));
        rightwall->setPosition(1920 - 300, 0);
        rightwall->setFillColor(sf::Color::Blue);

        leftwall->setSize(sf::Vector2f(50, 300));
        leftwall->setPosition(-500, 700);
        leftwall->setFillColor(sf::Color(158, 66, 245));

        obj1->setSize(sf::Vector2f(300, 50));
        obj1->setPosition(650, 850);

        objects = {Floor, obj1, leftwall, rightwall};
        hurts = {false,false,false,false};
    }
    else if (level == 3){
        sf::RectangleShape *Floor = new sf::RectangleShape();
        sf::RectangleShape *spikes = new sf::RectangleShape();
        sf::RectangleShape *stair1 = new sf::RectangleShape();
        sf::RectangleShape *stair2 = new sf::RectangleShape();
        sf::RectangleShape *stair3 = new sf::RectangleShape();
        finish_line->setSize(sf::Vector2f( 75, 75));
        finish_line->setPosition(500, 925);
        Floor->setSize(sf::Vector2f(2500, 80));
        Floor->setFillColor(sf::Color::Green);
        Floor->setPosition(-500, 1000);
        spikes->setSize(sf::Vector2f(50, 50));
        spikes->setFillColor(sf::Color::Red);
        spikes->setPosition(550, 950);
        stair3->setSize(sf::Vector2f(50, 50));
        stair3->setPosition(500, 900);
        stair2->setSize(sf::Vector2f(50, 50));
        stair2->setPosition(450, 850);
        stair1->setSize(sf::Vector2f(50, 50));
        stair1->setPosition(400, 800);
        objects = {Floor, spikes, stair1, stair2, stair3};
        hurts = {false, true, false,false,false};
    }
    if(level > 0){
        objects.insert(objects.begin(), finish_line);
        hurts.insert(hurts.begin(), false);
    }
}
