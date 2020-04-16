//
//  AssetManager.hpp
//  flappy-bird
//
//  Created by Kai Zheng on 4/16/20.
//  Copyright © 2020 kai. All rights reserved.
//

#pragma once

#include <map>

#include <SFML/Graphics.hpp>

namespace Kai {
    class AssetManager {
        public:
            AssetManager() {}
            ~AssetManager() {}
            
            void LoadTexture(std::string name, std::string fileName);
            sf::Texture &GetTexture(std::string name);
            
            void LoadFont(std::string name, std::string fileName);
            sf::Font &GetFont(std::string name);
            
            
        private:
            std::map<std::string, sf::Texture> _textures;
            std::map<std::string, sf::Font> _fonts;
    };
}
