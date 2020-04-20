//
//  MainMenuState.cpp
//  flappy-bird
//
//  Created by Kai Zheng on 4/20/20.
//  Copyright © 2020 kai. All rights reserved.
//


#include <sstream>
#include <iostream>
#include "MainMenuState.hpp"
#include "DEFINITIONS.hpp"



namespace Kai {
    MainMenuState::MainMenuState(GameDataRef data) : _data(data) {
        
    }
    
    void MainMenuState::Init() {
        _data->assets.LoadTexture("Main Menu Background", MAIN_MENU_BACKGROUND_FILEPATH);
        _data->assets.LoadTexture("Game Title", GAME_TITLE_FILEPATH);
        _data->assets.LoadTexture("Play Button", PLAY_BUTTON_FILEPATH);
        
        _background.setTexture(this->_data->assets.GetTexture("Main Menu Background"));
        _title.setTexture(this->_data->assets.GetTexture("Game Title"));
        _playButton.setTexture(this->_data->assets.GetTexture("Play Button"));
        
        _title.setPosition((SCREEN_WIDTH / 2) - (_title.getGlobalBounds().width / 2), _title.getGlobalBounds().height / 2);
        _playButton.setPosition((SCREEN_WIDTH / 2) - (_playButton.getGlobalBounds().width / 2), (SCREEN_HEIGHT / 2) - (_playButton.getGlobalBounds().height / 2));
    }
    
    void MainMenuState::HandleInput() {
        sf::Event event;
        
        while (_data->window.pollEvent(event)) {
            if (sf::Event::Closed == event.type) {
                _data->window.close();
            }
            
            if (_data->input.IsSpiteClicked(_playButton, sf::Mouse::Left, _data->window)) {
                std::cout << "Go To Game Screen" << std::endl;
            }
        }
    }
    
    void MainMenuState::Update(float dt) {
       
    }
    
    void MainMenuState::Draw(float dt) {
        
        _data->window.clear();
        
        _data->window.draw(_background);
        _data->window.draw(_title);
        _data->window.draw(_playButton);
        
        _data->window.display();
    }
}
