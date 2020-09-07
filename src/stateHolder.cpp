#include "ClassButtonPressed.hpp"
#include "DataButtonPressed.hpp"
#include "NoButtonPressed.hpp"
#include "State.hpp"

State::State()
{
    instance = make_unique<NoButtonPressed>();
};

mauseState *State::get()
{
    return instance.get();
}

void State::set(stateName chosen, wxToggleButton *s)
{
    switch (chosen)
    {
    case NoButton:
        instance = make_unique<NoButtonPressed>();
        break;
    case ClassButton:
        instance = make_unique<ClassButtonPressed>();
        break;
    case DataButton:
        instance = make_unique<DataButtonPressed>();
        break;
    case FunctionButton:
        break;
    case InheritanceButton:
        break;
    case FriendshipButton:
        break;
    case NestingButton:
        break;
    }
}
