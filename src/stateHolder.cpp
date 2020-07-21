#include "State.hpp"
#include "NoButtonPressed.hpp"
mauseState* State::get()
{
	return instance.get();
}

void State::set(stateName chosen, wxToggleButton* s)
{
	switch (chosen)
	{
	case NoButton:
		instance = make_unique< NoButtonPressed>();
		break;
	case ClassButton:
		instance = make_unique< ClassButtonPressed>();
		break;
	case DerrivedButton:
		break;
	case NestedButton:
		break;
	case DataButton:
		instance = make_unique< DataButtonPressed>();
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

mauseState* State::instance = make_unique<NoButtonPressed>();

