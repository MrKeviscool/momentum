#include <SFML/Graphics.hpp>
#include <vector>

sf::RectangleShape Floor(sf::Vector2f(1920, 80));
std::vector<sf::Shape*> objects = {&Floor};

void loadobjects(){
    Floor.setFillColor(sf::Color::Green);
    Floor.setPosition(0, 1000);
}

