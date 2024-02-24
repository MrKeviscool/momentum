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
#define gravity 0.15
#define ballsize 30
#define speedcap 10
#define decreasespeed 0.02
#define increasespeed 0.05
#define jumpheight 6
#define fps 125

int level = 1;

float rotation = 0;
bool touching_ground = false;
sf::Texture balltex;

//sf::Vector2f bpos;
sf::Vector2f bspeed;
sf::CircleShape ball(ballsize);


void calculaterotation(), display(sf::RenderWindow &window), logic(), delay(int delaytime), die(), win();
int main(){
    /////SETUP/////////
    loadlevel(level);
    sf::RenderWindow window(sf::VideoMode(1920, 1080), "Momentum", sf::Style::Fullscreen);
    if(!balltex.loadFromFile("./textures/blueball.png")){
        std::cout << "error loading texture\n";
        return 0;
    }
    balltex.setSmooth(true);
    ball.setTexture(&balltex);
    ball.setOrigin(ballsize, ballsize);
    ball.setPosition(screenwidth/2, screenheight/2);
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
    for(int i = 0; i < objects.size(); i++){
        if(screenwidth/2){
            
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

void die(){
    bspeed = sf::Vector2f(0,0);
    loadlevel(level);
}

void win(){
    bspeed = sf::Vector2f(0, 0);
    level++;
    loadlevel(level);

}