//
//  Game.hpp
//  flappy-bird
//
//  Created by Kai Zheng on 4/16/20.
//  Copyright © 2020 kai. All rights reserved.
//

#pragma once

#include <memory>
#include <string>
#include <SFML/Graphics.hpp>
#include "StateMachine.hpp"
#include "AssetManager.hpp"
#include "InputManager.hpp"

namespace Kai {
    struct GameData {
        StateMachine machine;
        sf::RenderWindow window;
        AssetManager assets;
        InputManager input;
    };
    
    typedef std::shared_ptr<GameData> GameDataRef;
    
    class Game {
        public:
            Game(int width, int height, std::string title);
            
        private:
            const float dt = 1.0f / 60.0f; // frame rate: we want to update 60 times per second
            sf::Clock _clock;
            
            GameDataRef _data = std::make_shared<GameData>();
            
            void Run();
    };
}
