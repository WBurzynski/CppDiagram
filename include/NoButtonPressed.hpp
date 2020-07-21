#pragma once

#include "mauseState.hpp"

class ClassPanel;
class DiagramWindow;
class NoButtonPressed : public mauseState
{
	bool dragging{ false };
	int x{ 0 }, y{ 0 };

	virtual void onClassDown(ClassPanel *panel, wxMouseEvent& event) override;
	virtual void onClassUp(ClassPanel *panel, wxMouseEvent& event) override;
	virtual void onClassMove(ClassPanel *panel, wxMouseEvent& event) override;

	virtual void onPanelDown(DiagramWindow* panel, wxMouseEvent& event) override;
};
