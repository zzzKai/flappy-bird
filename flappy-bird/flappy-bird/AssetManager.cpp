//
//  AssetManager.cpp
//  flappy-bird
//
//  Created by Kai Zheng on 4/16/20.
//  Copyright © 2020 kai. All rights reserved.
//

#include "AssetManager.hpp"

namespace Kai {
    void AssetManager::LoadTexture(std::string name, std::string fileName) {
        sf::Texture tex;
    
        if (tex.loadFromFile(fileName)) {
            this->_textures[name] = tex;
        }
    }
  
    sf::Texture &AssetManager::GetTexture(std::string name) {
        return this->_textures.at(name);
    }
    
    
    void AssetManager::LoadFont(std::string name, std::string fileName) {
        sf::Font font;
    
        if (font.loadFromFile(fileName)) {
            this->_fonts[name] = font;
        }
    }
  
    sf::Font &AssetManager::GetFont(std::string name) {
        return this->_fonts.at(name);
    }
}
