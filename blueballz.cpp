#include <iostream>
#include <SFML/Graphics.hpp>
#include <stdbool.h>
#include <math.h>
#include <vector>
#include <chrono>
#include <thread>
#include "objects.h"

#define screenwidth 1920
#define screenheight 1080
#define gravity 0.0784
#define ballsize 30
#define speedcap 5
#define decreasespeed 0.04
#define increasespeed 0.10
#define fps 125

float rotation = 0;
bool touching_ground = false;
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
    //bpos = sf::Vector2f(1920/2, 1080/2/*1080-(100+(ballsize/2) )+10*/);
    ball.setOrigin(ballsize, ballsize);
    ball.setPosition(1920/2, 1080/2);
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
    touching_ground = false;
    bool inwall = false;
    for(int s = 0; s < objects.size(); s++){
        if(screenwidth/2+(ballsize/2) < (objects[s]->getSize().x + objects[s]->getPosition().x) && screenwidth/2+(ballsize/2) > objects[s]->getPosition().x){
            if((screenheight/2)+ballsize+5 < (objects[s]->getSize().y + objects[s]->getPosition().y) && (screenheight/2)+ballsize+5 > objects[s]->getPosition().y){
                float move_amount = -(objects[s]->getPosition().y - ((screenheight/2)+ballsize));
                for(int o = 0; o < objects.size(); o++){
                    objects[o]->move(0, move_amount);
                }
                bspeed.y = 0;
                touching_ground = true;
            }
            else if(objects[s]->getPosition().y == 570){
                touching_ground = true;
                bspeed.y = 0;
            }
            
        }
        else if (!touching_ground){
            bspeed.y+=gravity;
        }

        if((screenwidth/2) + (ballsize/2) > objects[s]->getPosition().x && (screenwidth/2) + (ballsize/2) < objects[s]->getPosition().x + objects[s]->getSize().x){
            std::cout << "in wall\n";
            inwall = true;
        }
        else if (!inwall){
           std::cout << "not in wall wall\n"; 
        }
        
    }
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
    for(int i = 0; i < objects.size(); i++){
        objects[i]->move(-bspeed);
    }
    calculaterotation();
}

void display(sf::RenderWindow &window){
    window.clear(sf::Color::Black);
    window.draw(ball);
    for(int i = 0; i < objects.size(); i++){
        window.draw(*objects[i]);
    }
    window.display();
}

void delay(){ 
    std::this_thread::sleep_for(std::chrono::milliseconds(1000/fps));
    return;
}