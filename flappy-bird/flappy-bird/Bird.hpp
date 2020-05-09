//
//  Bird.hpp
//  flappy-bird
//
//  Created by Kai Zheng on 5/8/20.
//  Copyright © 2020 kai. All rights reserved.
//

#pragma once
#include <SFML/Graphics.hpp>

#include "DEFINITIONS.hpp"
#include "Game.hpp"

namespace Kai {
    class Bird {
        public:
            Bird(GameDataRef data);
            
            void Draw();
        
        private:
            GameDataRef _data;
            
            sf::Sprite _birdSprite;
    };
}
