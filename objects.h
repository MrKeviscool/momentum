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
        ground_right->setPosition(1200, 700);
        back_wall->setPosition(-200, 700);
        spike_pit->setPosition(1140, 800);

        ground_left->setSize(sf::Vector2f(1340, 300));
        objects = {ground_left};
        hurts = {false};

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
