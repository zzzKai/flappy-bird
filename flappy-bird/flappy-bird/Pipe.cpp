//
//  Pipe.cpp
//  flappy-bird
//
//  Created by Kai Zheng on 4/23/20.
//  Copyright © 2020 kai. All rights reserved.
//

#include "Pipe.hpp"

namespace Kai {
    Pipe::Pipe(GameDataRef data) : _data(data) {
    
    }
    
    void Pipe::DrawPipes() {
        for (unsigned short int i = 0; i < pipeSprites.size(); i++) {
            _data->window.draw(pipeSprites.at(i));
        }
    }
}
