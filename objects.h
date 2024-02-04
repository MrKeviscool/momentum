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
        Floor->setPosition(-500, 1000);
        //Floor->setFillColor(sf::Color::Green);
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
        Floor->setFillColor(sf::Color::Blue);
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
        sf::RectangleShape *botstair = new sf::RectangleShape();
        sf::RectangleShape *midstair = new sf::RectangleShape();
        sf::RectangleShape *topstair = new sf::RectangleShape();
        Floor->setSize(sf::Vector2f(2500, 100));
        Floor->setFillColor(sf::Color(235, 168, 52));
        Floor->setPosition(-500, 1000);
        finish_line->setSize(sf::Vector2f( 75, 75));
        finish_line->setPosition(1500, 925);
        botstair->setSize(sf::Vector2f(50, 50));
        spikes->setSize(sf::Vector2f(50, 50));
        midstair->setSize(sf::Vector2f(50, 50));
        topstair->setSize(sf::Vector2f(50, 50));
        spikes->setPosition(700, 950);
        botstair->setPosition(700, 900);
        midstair->setPosition(700, 850);
        topstair->setPosition(700, 950);
        objects = {Floor};
    }
    else{
        std::cout << "not a level yet :(\n";
        exit(0);
    }
    if(level > 0){
        objects.insert(objects.begin(), finish_line);
        hurts.insert(hurts.begin(), false);
    }
}
