//
//  SplashState.hpp
//  flappy-bird
//
//  Created by Kai Zheng on 4/17/20.
//  Copyright © 2020 kai. All rights reserved.
//

#pragma once

#include <SFML/Graphics.hpp>
#include "State.hpp"
#include "Game.hpp"

namespace Kai {
    class SplashState : public State {
        public:
            SplashState(GameDataRef data);
            
            void Init();
            
            void HandleInput();
            void Update(float dt);
            void Draw(float dt);
            
        private:
            GameDataRef _data;
            
            sf::Clock _clock;
            
            sf::Texture _backgroundTexture;
            sf::Sprite _background;
    };
}
