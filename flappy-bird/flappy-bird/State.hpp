//
//  State.hpp
//  flappy-bird
//
//  Created by Kai Zheng on 4/14/20.
//  Copyright © 2020 kai. All rights reserved.
//

#pragma once

namespace Kai {
    class State {
    public:
        virtual void Init() = 0;
       
        virtual void HandleInput() = 0;
        virtual void Update(float dt) = 0;
        virtual void Draw(float dt) = 0;
        
        virtual void Pause() {}
        virtual void Resume() {}
    };
}
