#include <SFML/Graphics.hpp>
#define ballsize 30
#define fps 0.008333333
float xspeed = 0, yspeed = 0, xpos = 30, ypos = 540, rotaionspd = 0;
sf::CircleShape ball(ballsize);
void calculaterotation(), display(), logic();
int main(){
    /////SETUP/////////
    sf::RenderWindow window(sf::VideoMode(1920, 1080), "Blue Ballz - MrKeviscool", sf::Style::Fullscreen);
    ///////END SETUP//////////
        while(window.isOpen()){ 
        sf::Event event;
        while (window.pollEvent(event))
        {
            if(event.type == sf::Event::Closed){
                window.close();
            }
        }
        ////////LOOP//////////
        display(window);
        //////END LOOP////////
    }
}

void calculaterotation(){

}

void display(sf::RenderWindow &window){
    window.clear(sf::Color::Black);
    window.draw(ball);
    display();
}