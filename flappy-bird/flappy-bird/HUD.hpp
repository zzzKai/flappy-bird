//
//  HUD.hpp
//  flappy-bird
//
//  Created by Kai Zheng on 5/21/20.
//  Copyright © 2020 kai. All rights reserved.
//

#pragma once

#include <SFML/Graphics.hpp>

#include "DEFINITIONS.hpp"
#include "Game.hpp"

namespace Kai {
    class HUD {
        public:
            HUD(GameDataRef data);
            
            void Draw();
            void UpdateScore(int score);
            
        private:
            GameDataRef _data;
            sf::Text _scoreText;
    };
}
