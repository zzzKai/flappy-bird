//
//  Flash.hpp
//  flappy-bird
//
//  Created by Kai Zheng on 5/17/20.
//  Copyright © 2020 kai. All rights reserved.
//

#pragma once

#include <SFML/Graphics.hpp>
#include "Game.hpp"
#include "DEFINITIONS.hpp"

namespace Kai {
    class Flash {
        public:
            Flash(GameDataRef data);
            
            void Show(float dt);
            void Draw();
            
        private:
            GameDataRef _data;
            
            sf::RectangleShape _shape;
            
            bool _flashOn;    
    };
}
