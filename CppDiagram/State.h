#pragma once

#include "mauseState.h"
#include "wx/tglbtn.h"
using std::unique_ptr;
using std::make_unique;
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
	static mauseState* get();
	static void set(stateName chosen, wxToggleButton* s);
	static  wxToggleButton* getSource();
	State() {};
private:
	static wxToggleButton* source;
	static unique_ptr<mauseState> instance;
};

