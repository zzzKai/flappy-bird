//
//  GameOverState.hpp
//  flappy-bird
//
//  Created by Kai Zheng on 4/22/20.
//  Copyright © 2020 kai. All rights reserved.
//

#pragma once

#include <SFML/Graphics.hpp>
#include "State.hpp"
#include "Game.hpp"

namespace Kai {
    class GameOverState : public State {
        public:
            GameOverState(GameDataRef data, int score);
            
            void Init();
            
            void HandleInput();
            void Update(float dt);
            void Draw(float dt);
            
        private:
            GameDataRef _data;
            
            sf::Sprite _background;
            
            sf::Sprite _gameOverTitle;
            sf::Sprite _gameOverContainer;
            sf::Sprite _retryButton;
            sf::Sprite _medal;
            
            sf::Text _scoreText;
            sf::Text _highScoreText;
            
            int _score;
            int _highScore;
    };
}
