//
//  Collision.hpp
//  flappy-bird
//
//  Created by Kai Zheng on 5/16/20.
//  Copyright © 2020 kai. All rights reserved.
//

#pragma once

#include <SFML/Graphics.hpp>

namespace Kai {
    class Collision {
        public:
            Collision();
            
            bool CheckSpriteCollision(sf::Sprite sprite1, sf::Sprite sprite2);
    };
}
