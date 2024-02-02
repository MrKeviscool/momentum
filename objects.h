#include <SFML/Graphics.hpp>
#include <vector>

sf::RectangleShape Floor;
sf::RectangleShape rightwall;
sf::RectangleShape leftwall;
sf::RectangleShape obj1;

std::vector<sf::RectangleShape *> objects;

void loadlevel(int level)
{
    if (level == 1)
    {
        Floor.setSize(sf::Vector2f(2500, 80));
        Floor.setFillColor(sf::Color::Green);
        Floor.setPosition(-500, 1000);

        rightwall.setSize((sf::Vector2f(200, 1080)));
        rightwall.setPosition(1920 - 300, 0);
        rightwall.setFillColor(sf::Color::Red);

        leftwall.setSize(sf::Vector2f(50, 300));
        leftwall.setPosition(-500, 700);

        obj1.setSize(sf::Vector2f(500, 50));
        obj1.setPosition(650, 800);

        objects = {&Floor, &obj1, &leftwall, &rightwall};
    }
}
