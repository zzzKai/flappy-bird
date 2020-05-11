//
//  Bird.cpp
//  flappy-bird
//
//  Created by Kai Zheng on 5/8/20.
//  Copyright © 2020 kai. All rights reserved.
//

#include "Bird.hpp"

namespace Kai {
    Bird::Bird(GameDataRef data) : _data(data) {        
        _animationIterator = 0;
        
        _animationFrames.push_back(_data->assets.GetTexture("Bird Frame 1"));
        _animationFrames.push_back(_data->assets.GetTexture("Bird Frame 2"));
        _animationFrames.push_back(_data->assets.GetTexture("Bird Frame 3"));
        _animationFrames.push_back(_data->assets.GetTexture("Bird Frame 4"));
        
        _birdSprite.setTexture(_animationFrames.at(_animationIterator));
    }
    
    void Bird::Draw() {
        _data->window.draw(_birdSprite);
    }
    
    void Bird::Animate(float dt) {
        if (_clock.getElapsedTime().asSeconds() > BIRD_ANIMATION_DURATION / _animationFrames.size()) {
            if (_animationIterator < _animationFrames.size() - 1) {
                _animationIterator++;
            } else {
                _animationIterator = 0;
            }
            
            _birdSprite.setTexture(_animationFrames.at(_animationIterator));
            
            _clock.restart();
        }    
    }
}
