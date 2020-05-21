//
//  GameState.hpp
//  flappy-bird
//
//  Created by Kai Zheng on 4/21/20.
//  Copyright © 2020 kai. All rights reserved.
//

#pragma once

#include <SFML/Graphics.hpp>
#include "State.hpp"
#include "Game.hpp"
#include "Pipe.hpp"
#include "Land.hpp"
#include "Bird.hpp"
#include "Collision.hpp"
#include "Flash.hpp"

namespace Kai {
    class GameState : public State {
        public:
            GameState(GameDataRef data);
            
            void Init();
            
            void HandleInput();
            void Update(float dt);
            void Draw(float dt);
            
        private:
            GameDataRef _data;
            
            sf::Sprite _background;
            
            Pipe *pipe;
            
            Land *land;
            
            Bird *bird;
            
            Collision collision;
            
            Flash *flash;
            
            sf::Clock clock;
            
            int _gameState;
            
            int _score;
    };
}
