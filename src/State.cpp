#include "State.hpp"
#include "NoButtonPressed.hpp"
#include "ClassButtonPressed.hpp"
#include "DataButtonPressed.hpp"
#include "FunctionButtonPressed.hpp"
#include "InheritanceButtonPressed.hpp"
#include "FriendshipButtonPressed.hpp"
#include "NestingButtonPressed.hpp"
mauseState* State::get()
{
	return instance.get();
}

void State::set(stateName chosen, wxToggleButton* s)
{
	source = s;
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
		instance = make_unique<FunctionButtonPressed>();
		break;
	case InheritanceButton:
		instance = make_unique<InheritanceButtonPressed>();
		break;
	case FriendshipButton:
		instance = make_unique<FriendshipButtonPressed>();
		break;
	case NestingButton:
		instance = make_unique<NestingButtonPressed>();
		break;
	}
}

wxToggleButton* State::getSource()
{
	return source;
}

unique_ptr<mauseState> State::instance = make_unique < NoButtonPressed>();

wxToggleButton* State::source = nullptr;
