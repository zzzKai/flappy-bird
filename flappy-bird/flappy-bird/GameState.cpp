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
        
        _data->assets.LoadTexture("Bird Frame 1", BIRD_FRAME_1_FILEPATH);
        _data->assets.LoadTexture("Bird Frame 2", BIRD_FRAME_2_FILEPATH);
        _data->assets.LoadTexture("Bird Frame 3", BIRD_FRAME_3_FILEPATH);
        _data->assets.LoadTexture("Bird Frame 4", BIRD_FRAME_4_FILEPATH);
        
        pipe = new Pipe(_data);
        land = new Land(_data);
        bird = new Bird(_data);
        flash = new Flash(_data);
        
        _background.setTexture(this->_data->assets.GetTexture("Game Background"));
        
        _gameState = GameStates::eReady;
    }
    
    void GameState::HandleInput() {
        sf::Event event;
        
        while (_data->window.pollEvent(event)) {
            if (sf::Event::Closed == event.type) {
                _data->window.close();
            }
            
            if (_data->input.IsSpiteClicked(_background, sf::Mouse::Left, _data->window)) {
                if (_gameState != GameStates::eGameOver) {
                    _gameState = GameStates::ePlaying;
                    bird->Tap();
                }
            }
        }
    }
    
    void GameState::Update(float dt) {
        if (_gameState != GameStates::eGameOver) {
            bird->Animate(dt);
            land->MoveLand(dt);
        }
        
        if (_gameState == GameStates::ePlaying) {
            pipe->MovePipes(dt);
            
            if (clock.getElapsedTime().asSeconds() > PIPE_SPAWN_FREQUENCY) {
                pipe->RandomizePipeOffset();
            
                pipe->SpawnInvisiblePipe();
                pipe->SpawnBottomPipe();
                pipe->SpawnTopPipe();
                
                clock.restart();
            }
            
            bird->Update(dt);
            
            std::vector<sf::Sprite> landSprites = land->GetSprites();
            for (int i = 0; i < landSprites.size(); i++) {
                if (collision.CheckSpriteCollision(bird->GetSprite(), 0.7f, landSprites.at(i), 1.0f)) {
                    _gameState = GameStates::eGameOver;
                }
            }
            
            std::vector<sf::Sprite> pipeSprites = pipe->GetSprites();
            for (int i = 0; i < pipeSprites.size(); i++) {
                if (collision.CheckSpriteCollision(bird->GetSprite(), 0.625f, pipeSprites.at(i), 1.0f)) {
                    _gameState = GameStates::eGameOver;
                }
            }
        }
        
        if (_gameState == GameStates::eGameOver) {
            flash->Show(dt);
        }
    }
    
    void GameState::Draw(float dt) {
        
        _data->window.clear();
        
        _data->window.draw(_background);
        
        pipe->DrawPipes();
        land->DrawLand();
        bird->Draw();
        flash->Draw();
        
        _data->window.display();
    }
}
