#pragma once

#include "mauseState.h"
class ClassPanel;
class DiagramWindow;
class ClassButtonPressed : public mauseState
{
	void onClassDown(ClassPanel* panel, wxMouseEvent& event) override;

	void onPanelDown(DiagramWindow* panel, wxMouseEvent& event) override;

	friend class State;
};

