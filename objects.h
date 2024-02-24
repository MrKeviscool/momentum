#include <SFML/Graphics.hpp>
#include <vector>
#include <stdbool.h>
#define blocksize 30

void moveblocks();

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
        ground_left->setPosition(-7, 20);
        ground_right->setPosition(50, 20);
        back_wall->setPosition(-7, 10);
        spike_pit->setPosition(33 , 22);
        finish_line->setPosition(60, 13);

        ground_left->setSize(sf::Vector2f(40, 6));
        ground_right->setSize(sf::Vector2f(16, 6));
        back_wall->setSize(sf::Vector2f(3, 16));
        spike_pit->setSize(sf::Vector2f(17, 4));
        finish_line->setSize(sf::Vector2f(3, 8));
        objects = {ground_left, ground_right, back_wall, spike_pit};
        hurts = {false, false, false, true};
        moveblocks();

    }
    else if(level == 2){
        sf::RectangleShape *ground = new sf::RectangleShape();
        sf::RectangleShape *back_wall = new sf::RectangleShape();
        sf::RectangleShape *spike1 = new sf::RectangleShape();
        sf::RectangleShape *spike2 = new sf::RectangleShape();
        sf::RectangleShape *spike3 = new sf::RectangleShape();
        sf::RectangleShape *spike4 = new sf::RectangleShape();
        ground->setPosition(0, 20);
        back_wall->setPosition(0, 10);
        spike1->setPosition(35, 15);
        spike2->setPosition(42, 15);
        spike3->setPosition(49, 15);
        spike4->setPosition(66, 15);

        ground->setSize(sf::Vector2f(40, 6));
        back_wall->setSize(sf::Vector2f(3, 16));
        spike1->setSize(sf::Vector2f(3.5, 5));
        spike2->setSize(sf::Vector2f(3.5, 5));
        spike3->setSize(sf::Vector2f(3.5, 5));
        spike4->setSize(sf::Vector2f(3.5, 5));
        finish_line->setPosition(40, 13);
        finish_line->setSize(sf::Vector2f(3, 8));
        objects = {ground, back_wall, spike1,spike2,spike3,spike4};
        hurts = {false, false, true,true,true,true};
        moveblocks();

    }
    else  if(level == 3){
        sf::RectangleShape *ground_left = new sf::RectangleShape();
        sf::RectangleShape *randomblock = new sf::RectangleShape();
        randomblock->setPosition(10, 40);
        ground_left->setPosition(0, 80);
        ground_left->setSize(sf::Vector2f(40, 6));
        randomblock->setSize(sf::Vector2f(3, 10));
        objects = {ground_left, randomblock};
        hurts = {false, false};
        moveblocks();
    }
    else{
        std::cout << "not a level yet :(\n";
        exit(0);
    }
}

void moveblocks(){
    objects.insert(objects.begin(), finish_line);
    hurts.insert(hurts.begin(), false);
    for(int i = 0; i < objects.size(); i++){
        objects[i]->setPosition(objects[i]->getPosition().x * blocksize, objects[i]->getPosition().y * blocksize);
        objects[i]->setSize(sf::Vector2f(objects[i]->getSize().x * blocksize, objects[i]->getSize().y * blocksize));
        if(hurts[i] == true){objects[i]->setFillColor(sf::Color::Red);}
    }
}