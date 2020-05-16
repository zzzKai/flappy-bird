//
//  Land.hpp
//  flappy-bird
//
//  Created by Kai Zheng on 5/5/20.
//  Copyright © 2020 kai. All rights reserved.
//

#pragma once

#include <SFML/Graphics.hpp>
#include "Game.hpp"
#include <vector>

namespace Kai {
    class Land {
        public:
            Land(GameDataRef data);
            
            void MoveLand(float dt);
            void DrawLand();
            
            const std::vector<sf::Sprite> &GetSprites() const;
            
        private:
            GameDataRef _data;
            std::vector<sf::Sprite> _landSprites;
    };
}
