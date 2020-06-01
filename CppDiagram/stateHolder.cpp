#include "State.h"

mauseState* State::getState()
{
	return instance;
}

void State::setState(stateName chosen)
{
	switch (chosen)
	{
	case NoButton:
		instance = new NoButtonPressed();
		break;
	case ClassButton:
		instance = new ClassButtonPressed();
		break;
	case DerrivedButton:
		break;
	case NestedButton:
		break;
	case DataButton:
		instance = new DataButtonPressed();
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

mauseState* State::instance = new NoButtonPressed();

