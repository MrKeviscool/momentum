#include <SFML/Graphics.hpp>
#include <vector>

sf::RectangleShape Floor(sf::Vector2f(2500, 80));
sf::RectangleShape wallright(sf::Vector2f(200, 1080));
sf::RectangleShape anotherfloor(sf::Vector2f(500, 50));
sf::RectangleShape leftwall(sf::Vector2f(50, 300));
sf::RectangleShape box1(sf::Vector2f(50,50));
sf::RectangleShape lowfloor(sf::Vector2f(300, 50));
sf::RectangleShape box2(sf::Vector2f(50, 50));

std::vector<sf::RectangleShape*> objects = {&Floor, &wallright, &anotherfloor, &leftwall, &box1, &box2};

void loadobjects(){
    Floor.setFillColor(sf::Color::Green);
    Floor.setPosition(-500, 1000); 
    wallright.setPosition(1920 - 300, 0);
    wallright.setFillColor(sf::Color::Red);
    anotherfloor.setPosition(650, 800);
    leftwall.setPosition(-500, 700);
    box1.setPosition(400, 1000-50);
    box2.setPosition(450, 1000-100);
    lowfloor.setPosition(300, 850);;
}

