//
//  InputManager.hpp
//  flappy-bird
//
//  Created by Kai Zheng on 4/16/20.
//  Copyright © 2020 kai. All rights reserved.
//

#pragma once

#include <SFML/Graphics.hpp>

namespace Kai {
    class InputManager {
        public:
            InputManager() {}
            ~InputManager() {}
            
            bool IsSpiteClicked(sf::Sprite object, sf::Mouse::Button button, sf::RenderWindow &window);
            
            sf::Vector2i GetMousePosition(sf::RenderWindow &window);
    };
}
