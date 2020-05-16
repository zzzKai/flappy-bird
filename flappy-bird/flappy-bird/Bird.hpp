//
//  Bird.hpp
//  flappy-bird
//
//  Created by Kai Zheng on 5/8/20.
//  Copyright © 2020 kai. All rights reserved.
//

#pragma once
#include <SFML/Graphics.hpp>

#include "DEFINITIONS.hpp"
#include "Game.hpp"
#include <vector>

namespace Kai {
    class Bird {
        public:
            Bird(GameDataRef data);
            
            void Draw();
            
            void Animate(float dt);
            
            void Update(float dt);
            
            void Tap();
            
            const sf::Sprite &GetSprite() const;
            
        private:
            GameDataRef _data;
            
            sf::Sprite _birdSprite;
            
            std::vector<sf::Texture> _animationFrames;
            
            unsigned int _animationIterator;
            
            sf::Clock _clock;
            
            sf::Clock _movementClock;
            
            int _birdState;
            
            float _rotation;
    };
}
