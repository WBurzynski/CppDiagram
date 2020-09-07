#pragma once

#include <memory>

//#include "mauseState.h"
#include "ClassButtonPressed.h"
#include "NoButtonPressed.h"
using std::make_unique;
using std::unique_ptr;
class State
{
  public:
    enum stateName
    {
        NoButton,
        ClassButton,
        DerrivedButton,
        NestedButton,
        DataButton,
        FunctionButton,
        InheritanceButton,
        FriendshipButton,
        NestingButton
    };
    static mauseState *getState();
    static void setState(stateName chosen);
    State(){};

  private:
    static mauseState *instance;
};
