#pragma once

#include "mauseState.hpp"
#include "wx/tglbtn.h"
#include <memory>
using std::make_unique;
using std::unique_ptr;
class State
{
  public:
    enum stateName
    {
        NoButton,
        ClassButton,
        DataButton,
        FunctionButton,
        InheritanceButton,
        FriendshipButton,
        NestingButton
    };
    static mauseState *get();
    static void set(stateName chosen, wxToggleButton *s);
    static wxToggleButton *getSource();
    State();

  private:
    static wxToggleButton *source;
    static unique_ptr<mauseState> instance;
};
