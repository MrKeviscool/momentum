#include <SFML/Graphics.hpp>
#include <vector>
#include <stdbool.h>

std::vector<sf::RectangleShape *> objects;
std::vector<bool> hurts;

void loadlevel(int level)
{
    if (level == 1)
    {
        sf::RectangleShape *Floor = new sf::RectangleShape();
        sf::RectangleShape *rightwall = new sf::RectangleShape();
        sf::RectangleShape *leftwall = new sf::RectangleShape();
        sf::RectangleShape *obj1 = new sf::RectangleShape();

        Floor->setSize(sf::Vector2f(2500, 80));
        Floor->setFillColor(sf::Color::Green);
        Floor->setPosition(-500, 1000);

        rightwall->setSize((sf::Vector2f(200, 1080)));
        rightwall->setPosition(1920 - 300, 0);
        rightwall->setFillColor(sf::Color::Red);

        leftwall->setSize(sf::Vector2f(50, 300));
        leftwall->setPosition(-500, 700);

        obj1->setSize(sf::Vector2f(500, 50));
        obj1->setPosition(650, 800);

        objects = {Floor, obj1, leftwall, rightwall};
    }
    else if(level == 2){
        sf::RectangleShape *Floor = new sf::RectangleShape();
        sf::RectangleShape *rightwall = new sf::RectangleShape();
        sf::RectangleShape *leftwall = new sf::RectangleShape();
        sf::RectangleShape *obj1 = new sf::RectangleShape();

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
        obj1->setPosition(650, 900);

        objects = {Floor, obj1, leftwall, rightwall};
    }
    else if (level == 3){
        sf::RectangleShape *Floor = new sf::RectangleShape();
        sf::RectangleShape *spikes = new sf::RectangleShape();
        Floor->setSize(sf::Vector2f(2500, 80));
        Floor->setFillColor(sf::Color::Green);
        Floor->setPosition(-500, 1000);
        spikes->setSize(sf::Vector2f(50, 50));
        spikes->setFillColor(sf::Color::Red);
        spikes->setPosition(300, 950);
        objects = {Floor, spikes};
        hurts = {false, true};
    }
}
