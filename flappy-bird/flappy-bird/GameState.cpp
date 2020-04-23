//
//  GameState.cpp
//  flappy-bird
//
//  Created by Kai Zheng on 4/21/20.
//  Copyright © 2020 kai. All rights reserved.
//

#include <sstream>
#include <iostream>
#include "GameState.hpp"
#include "DEFINITIONS.hpp"



namespace Kai {
    GameState::GameState(GameDataRef data) : _data(data) {
        
    }
    
    void GameState::Init() {
        
        std::cout << "Game State" << std::endl;
        
        _data->assets.LoadTexture("Game Background", GAME_BACKGROUND_FILEPATH);
        
        _background.setTexture(this->_data->assets.GetTexture("Game Background"));
    }
    
    void GameState::HandleInput() {
        sf::Event event;
        
        while (_data->window.pollEvent(event)) {
            if (sf::Event::Closed == event.type) {
                _data->window.close();
            }
        }
    }
    
    void GameState::Update(float dt) {
        
    }
    
    void GameState::Draw(float dt) {
        
        _data->window.clear();
        
        _data->window.draw(_background);
        
        _data->window.display();
    }
}