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
        
        _data->assets.LoadTexture("Game Background", GAME_BACKGROUND_FILEPATH);
        
        _data->assets.LoadTexture("Pipe Up", PIPE_UP_FILEPATH);
        
        _data->assets.LoadTexture("Pipe Down", PIPE_DOWN_FILEPATH);
        
        _data->assets.LoadTexture("Land", LAND_FILEPATH);
        
        pipe = new Pipe(_data);
        land = new Land(_data);
        
        _background.setTexture(this->_data->assets.GetTexture("Game Background"));
    }
    
    void GameState::HandleInput() {
        sf::Event event;
        
        while (_data->window.pollEvent(event)) {
            if (sf::Event::Closed == event.type) {
                _data->window.close();
            }
            
            if (_data->input.IsSpiteClicked(_background, sf::Mouse::Left, _data->window)) {
                
            }
        }
    }
    
    void GameState::Update(float dt) {
        pipe->MovePipes(dt);
        land->MoveLand(dt);
        
        if (clock.getElapsedTime().asSeconds() > PIPE_SPAWN_FREQUENCY) {
            pipe->RandomizePipeOffset();
        
            pipe->SpawnInvisiblePipe();
            pipe->SpawnBottomPipe();
            pipe->SpawnTopPipe();
            
            clock.restart();
        }
    }
    
    void GameState::Draw(float dt) {
        
        _data->window.clear();
        
        _data->window.draw(_background);
        
        pipe->DrawPipes();
        land->DrawLand();
        
        _data->window.display();
    }
}
