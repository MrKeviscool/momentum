#include <SFML/Graphics.hpp>
#include <vector>
#include <stdbool.h>

std::vector<sf::RectangleShape *> objects;
std::vector<bool> hurts;
sf::RectangleShape *finish_line = new sf::RectangleShape();
void loadlevel(int level)
{
    finish_line->setFillColor(sf::Color::Green);
    if(level == 1){
        sf::RectangleShape *ground_left = new sf::RectangleShape();
        sf::RectangleShape *ground_right = new sf::RectangleShape();
        sf::RectangleShape *spike_pit = new sf::RectangleShape();
        sf::RectangleShape *back_wall = new sf::RectangleShape();

        spike_pit->setFillColor(sf::Color::Red);

        ground_left->setPosition(-200, 700);
        ground_right->setPosition(1600, 700);
        back_wall->setPosition(-200, 300);
        spike_pit->setPosition(1040, 800);
        finish_line->setPosition(2000, 500);

        ground_left->setSize(sf::Vector2f(1240, 300));
        ground_right->setSize(sf::Vector2f(500, 300));
        back_wall->setSize(sf::Vector2f(100, 500));
        spike_pit->setSize(sf::Vector2f(560, 200));
        finish_line->setSize(sf::Vector2f(100, 200));

        objects = {ground_left, ground_right, back_wall, spike_pit};
        hurts = {false, false, false, true};

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
