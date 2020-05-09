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
        _birdSprite.setTexture(_data->assets.GetTexture("Bird Frame 1"));
    }
    
    void Bird::Draw() {
        _data->window.draw(_birdSprite);
    }
}
