//
//  Collision.cpp
//  flappy-bird
//
//  Created by Kai Zheng on 5/16/20.
//  Copyright © 2020 kai. All rights reserved.
//

#include "Collision.hpp"

namespace Kai {
    Collision::Collision() {
        
    }
    
    bool Collision::CheckSpriteCollision(sf::Sprite sprite1, sf::Sprite sprite2) {
        sf::Rect<float> rect1 = sprite1.getGlobalBounds();
        sf::Rect<float> rect2 = sprite2.getGlobalBounds();
        
        if (rect1.intersects(rect2)) {
            return true;
        } else {
            return false;
        }
    }
}
