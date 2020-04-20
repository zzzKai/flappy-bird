//
//  MainMenuState.hpp
//  flappy-bird
//
//  Created by Kai Zheng on 4/20/20.
//  Copyright © 2020 kai. All rights reserved.
//

#pragma once

#include <SFML/Graphics.hpp>
#include "State.hpp"
#include "Game.hpp"

namespace Kai {
    class MainMenuState : public State {
        public:
            MainMenuState(GameDataRef data);
            
            void Init();
            
            void HandleInput();
            void Update(float dt);
            void Draw(float dt);
            
        private:
            GameDataRef _data;

            sf::Sprite _background;
            sf::Sprite _title;
            sf::Sprite _playButton;
    };
}
