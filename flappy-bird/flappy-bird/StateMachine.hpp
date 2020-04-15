//
//  StateMachine.hpp
//  flappy-bird
//
//  Created by Kai Zheng on 4/14/20.
//  Copyright © 2020 kai. All rights reserved.
//

#pragma once

#include <memory>
#include <stack>

#include "State.hpp"

namespace Kai {
    typedef std::unique_ptr<State> StateRef;
    
    class StateMachine {
    public:
        StateMachine() {}
        ~StateMachine() {}
        
        void AddState(StateRef newState, bool isReplacing = true);
        void RemoveState();
        
        void ProcessStateChanges();
        
        StateRef &GetActiveState();
        
    private:
        std::stack<StateRef> _states;
        StateRef _newState;
        
        bool _isRemoving;
        bool _isAdding;
        bool _isReplacing;
    };
}
