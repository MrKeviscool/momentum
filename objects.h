#include <SFML/Graphics.hpp>
#include <vector>

sf::RectangleShape Floor(sf::Vector2f(1920, 80));
sf::RectangleShape wallright(sf::Vector2f(200, 1080));
sf::RectangleShape anotherfloor(sf::Vector2f(500, 50));
sf::RectangleShape leftwall(sf::Vector2f(50, 300));
sf::RectangleShape box1(sf::Vector2f(50,30));
std::vector<sf::RectangleShape*> objects = {&Floor, &wallright, &anotherfloor, &leftwall, &box1};

void loadobjects(){
    Floor.setFillColor(sf::Color::Green);
    Floor.setPosition(0, 1000); 
    wallright.setPosition(1920 - 300, 0);
    wallright.setFillColor(sf::Color::Red);
    anotherfloor.setPosition(600, 800);
    leftwall.setPosition(50, 700);
    box1.setPosition(100, 1000-30);
}

