//
//  Pipe.hpp
//  flappy-bird
//
//  Created by Kai Zheng on 4/23/20.
//  Copyright © 2020 kai. All rights reserved.
//

#pragma once

#include <SFML/Graphics.hpp>
#include "Game.hpp"
#include <vector>

namespace Kai {
    class Pipe {
        public:
            Pipe(GameDataRef data);
            
            void DrawPipes();
            
        private:
            GameDataRef _data;
            std::vector<sf::Sprite> pipeSprites;
    };
}
