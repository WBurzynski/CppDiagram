#pragma once

#include "mauseState.h"

class ClassPanel;
class DiagramWindow;
class NoButtonPressed : public mauseState
{
	bool dragging{ false };
	int x{ 0 }, y{ 0 };

	void onClassDown(ClassPanel *panel, wxMouseEvent& event) override;
	void onClassUp(ClassPanel *panel, wxMouseEvent& event) override;
	void onClassMove(ClassPanel *panel, wxMouseEvent& event) override;

	void onPanelDown(DiagramWindow* panel, wxMouseEvent& event) override;
};