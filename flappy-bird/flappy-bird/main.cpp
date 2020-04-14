//
//  main.cpp
//  flappy-bird
//
//  Created by Kai Zheng on 4/14/20.
//  Copyright © 2020 kai. All rights reserved.
//

#include <SFML/Graphics.hpp>
#include <iostream>

#define SCREEN_WIDTH 1024
#define SCREEN_HEIGHT 1024

int main() {
    sf::RenderWindow window(sf::VideoMode(SCREEN_WIDTH, SCREEN_HEIGHT), "Flappy Bird");
    
    while (window.isOpen()) {
        // handle input/events
        sf::Event event;
        
        while (window.pollEvent(event)) {
            switch (event.type) {
                case sf::Event::Closed:
                    window.close();
                    break;
            }
        }
        
        // update game logic
        
        window.clear();
        
        // draw objects
        window.display();
    }
    return EXIT_SUCCESS;
}
