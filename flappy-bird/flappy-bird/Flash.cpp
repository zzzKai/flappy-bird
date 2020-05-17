//
//  Flash.cpp
//  flappy-bird
//
//  Created by Kai Zheng on 5/17/20.
//  Copyright © 2020 kai. All rights reserved.
//

#include "Flash.hpp"

namespace Kai {
    Flash::Flash(GameDataRef data) : _data(data) {
        _shape = sf::RectangleShape(sf::Vector2f(_data->window.getSize()));
        _shape.setFillColor(sf::Color(255, 255, 255, 0));
        _flashOn = true;
    }
    
    void Flash::Show(float dt) {
        if (_flashOn) {
            int alpha = (int)_shape.getFillColor().a + (FLASH_SPEED * dt);
            
            if (alpha >= 255.0f) {
                alpha = 255.0f;
                _flashOn = false;
            }
            _shape.setFillColor(sf::Color(255, 255, 255, alpha));
        } else {
            int alpha = (int)_shape.getFillColor().a - (FLASH_SPEED * dt);
            
            if (alpha <= 0.0f) {
                alpha = 0.0f;
                _flashOn = false;
            }
            _shape.setFillColor(sf::Color(255, 255, 255, alpha));
        }
    }
    
    void Flash::Draw() {
        _data->window.draw(_shape);
    }
}
