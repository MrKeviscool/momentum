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
#define gravity 0.15//0.0784
#define ballsize 30
#define speedcap 10
#define decreasespeed 0.02
#define increasespeed 0.05
#define jumpheight 6
#define fps 125

float rotation = 0;
bool touching_ground = false;
sf::Texture balltex;

sf::Vector2f bpos;
sf::Vector2f bspeed;
sf::CircleShape ball(ballsize);


void calculaterotation(), display(sf::RenderWindow &window), logic(), delay(int delaytime);
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
        std::chrono::steady_clock::time_point starttime = std::chrono::steady_clock::now();
        logic();
        display(window);
        std::chrono::steady_clock::time_point endtime = std::chrono::steady_clock::now();
        delay(std::chrono::duration_cast<std::chrono::milliseconds> (endtime - starttime).count());
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
    bool inrightwall = false, inleftwall = false;
    for(int s = 0; s < objects.size(); s++){

        //bottom collison
        if(((screenwidth/2) - (ballsize/2)) < (objects[s]->getSize().x + objects[s]->getPosition().x) && ((screenwidth/2) + (ballsize/2)) > objects[s]->getPosition().x){
            if((screenheight/2)+ballsize <= (objects[s]->getSize().y + objects[s]->getPosition().y) && (screenheight/2)+ballsize >= objects[s]->getPosition().y){
                float move_amount = -(objects[s]->getPosition().y - ((screenheight/2)+ballsize));
                for(int o = 0; o < objects.size(); o++){
                    objects[o]->move(0, move_amount);
                }
                bspeed.y = 0;
                touching_ground = true;
            }
            /*else if(objects[s]->getPosition().y == 570){
                touching_ground = true;
                bspeed.y = 0;
            }*/
            
        }
        //right collison
        if((screenheight/2) > objects[s]->getPosition().y && screenheight/2 < objects[s]->getPosition().y + objects[s]->getSize().y){
            if(((screenwidth/2) + ballsize) > objects[s]->getPosition().x && ((screenwidth/2)+ballsize) < objects[s]->getPosition().x + objects[s]->getSize().x){
                inrightwall = true;
                float move_amount = -(objects[s]->getPosition().x - ((screenwidth/2)+ballsize));
                for(int o = 0; o < objects.size(); o++){
                    objects[o]->move(move_amount,0);
                }
                bspeed.x = 0;
            }
        }
        //left collison
        if((screenheight/2) > objects[s]->getPosition().y && screenheight/2 < objects[s]->getPosition().y + objects[s]->getSize().y){
            if((screenwidth/2) - ballsize > objects[s]->getPosition().x && (screenwidth/2) - ballsize < objects[s]->getPosition().x + objects[s]->getSize().x){
                float move_amount = -(objects[s]->getPosition().x+objects[s]->getSize().x - ((screenwidth/2)-ballsize));
                inleftwall = true;
                for(int o = 0; o < objects.size(); o++){
                    objects[o]->move(move_amount,0);
                }
                bspeed.x = 0;
            }
        }
        //top collision
       if(screenwidth/2 > objects[s]->getPosition().x && screenwidth/2 < objects[s]->getPosition().x + objects[s]->getSize().x){
            if((screenheight/2)-ballsize > objects[s]->getPosition().y && (screenheight/2)-ballsize < objects[s]->getPosition().y + objects[s]->getSize().y){
                float move_amount = ( (objects[s]->getPosition().y + objects[s]->getSize().y) - ((screenheight/2)));
                for(int o = 0; o < objects.size(); o++){
                    objects[o]->move(0,move_amount);
                    bspeed.y = 0;
                }
            }
       }
    }
    

    if (!touching_ground){
        bspeed.y+=gravity;
    }
        
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Right)&& !sf::Keyboard::isKeyPressed(sf::Keyboard::Left) && bspeed.x < speedcap && !inrightwall){
        bspeed.x+=increasespeed;
    }
    else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Left) && !sf::Keyboard::isKeyPressed(sf::Keyboard::Right) && bspeed.x > -speedcap && !inleftwall){
       bspeed.x-=increasespeed;
    }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Up)&&touching_ground){
        bspeed.y -= jumpheight;
        touching_ground = false;
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

void delay(int delaytime){ 
    std::this_thread::sleep_for(std::chrono::milliseconds((1000/fps)-delaytime));
    return;
}