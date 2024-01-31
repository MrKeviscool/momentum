#include <iostream>
#include <SFML/Graphics.hpp>
#include <stdbool.h>
#include <math.h>
#include <vector>
#include "objects.h"

#define gravity 0.0784
#define ballsize 30
#define speedcap 3
#define decreasespeed 0.02
#define increasespeed 0.05
#define fps 0.008 //0.008 = 125

float rotation = 0;
bool touching_ground = true;
sf::Texture balltex;

sf::Vector2f bpos;
sf::Vector2f bspeed;
sf::CircleShape ball(ballsize);


void calculaterotation(), display(sf::RenderWindow &window), logic(), delay();
int main(){
    /////SETUP/////////
    loadobjects();
    sf::RenderWindow window(sf::VideoMode(1920, 1080), "Blue Ballz - MrKeviscool", sf::Style::Fullscreen);
    if(!balltex.loadFromFile("./textures/blueball.png")){
        std::cout << "error loading texture\n";
        return 0;
    }
    balltex.setSmooth(true);
    ball.setTexture(&balltex);
    bpos = sf::Vector2f(100, 200);
    ball.setOrigin(ballsize, ballsize);
    ball.setPosition(bpos);
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
        logic();
        display(window);
        delay();
        //////END LOOP////////
    }
}

void calculaterotation(){
    rotation+=(bspeed.x/(30*M_PI))*360;
    if(rotation > 360){
        rotation -= 360;
    }
    else if(rotation < 0){
        rotation+=360;
    }
    ball.setRotation(rotation);
}

void logic(){
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Right)&& !sf::Keyboard::isKeyPressed(sf::Keyboard::Left) && bspeed.x < speedcap){
        bspeed.x+=increasespeed;
    }
    else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Left) && !sf::Keyboard::isKeyPressed(sf::Keyboard::Right) && bspeed.x > -speedcap){
       bspeed.x-=increasespeed;
    }
    else if(bspeed.x > 0 && touching_ground){
        bspeed.x -= decreasespeed;
        if(bspeed.x <= decreasespeed){
            bspeed.x = 0.0;
        }
    }
    else if (bspeed.x < 0 && touching_ground){
        bspeed.x += decreasespeed;
        if(bspeed.x >= -decreasespeed){
            bspeed.x = 0.0;
        }
    }
    //ball.move(bspeed);
    bspeed.y -= gravity;
    calculaterotation();
}

void display(sf::RenderWindow &window){
    window.clear(sf::Color::Black);
    window.draw(ball);
    window.draw(*objects[0]);
    window.display();
}

void delay(){ 
    unsigned long tix = (fps * CLOCKS_PER_SEC);
    unsigned long newtix = clock() + tix;
    while (newtix > clock()){}
    return;
}