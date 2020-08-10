#pragma once

#include <memory>

//#include "mauseState.h"
#include "NoButtonPressed.h"
#include "ClassButtonPressed.h"
using std::unique_ptr;
using std::make_unique;
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
	static mauseState* getState();
	static void setState(stateName chosen);
	State() {};
private:
	static mauseState* instance;
};

