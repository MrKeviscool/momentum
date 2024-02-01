#include <SFML/Graphics.hpp>
#include <vector>

sf::RectangleShape Floor(sf::Vector2f(1920, 80));
sf::RectangleShape wallright(sf::Vector2f(200, 1080));
sf::RectangleShape anotherfloor(sf::Vector2f(500, 50));
std::vector<sf::RectangleShape*> objects = {&Floor, &wallright/*, &anotherfloor*/};

void loadobjects(){
    Floor.setFillColor(sf::Color::Green);
    Floor.setPosition(0, 1000); 
    wallright.setPosition(1920 - 300, 0);
    wallright.setFillColor(sf::Color::Red);
    anotherfloor.setPosition(200, 800);

}

