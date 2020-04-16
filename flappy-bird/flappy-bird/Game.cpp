//
//  Game.cpp
//  flappy-bird
//
//  Created by Kai Zheng on 4/16/20.
//  Copyright © 2020 kai. All rights reserved.
//

#include "Game.hpp"

namespace Kai {
    Game::Game(int width, int height, std::string title) {
        _data->window.create(sf::VideoMode(width, height), title, sf::Style::Close | sf::Style::Titlebar);
        
        
        this->Run();
    }
    
    void Game::Run() {
        float newTime, frameTime, interpolation;
        
        float currentTime = this->_clock.getElapsedTime().asSeconds();
        
        float accumulator = 0.0f;
        
        while (this->_data->window.isOpen()) {
            this->_data->machine.ProcessStateChanges();
            
            newTime = this->_clock.getElapsedTime().asSeconds();
            frameTime = newTime - currentTime;
            
            if (frameTime > 0.25f) {
                frameTime = 0.25f;
            }
            
            currentTime = newTime;
            accumulator += frameTime;
            
            while (accumulator >= dt) {
                this->_data->machine.GetActiveState()->HandleInput();
                this->_data->machine.GetActiveState()->Update(dt);
                accumulator -= dt;
            }
            
            interpolation = accumulator / dt;
            this->_data->machine.GetActiveState()->Draw(interpolation);
        }
    }
}
