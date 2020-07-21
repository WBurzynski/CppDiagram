#pragma once
#include "wx/event.h"


class ClassPanel;
class DiagramWindow;
class mauseState
{
public:
	virtual void onClassDown(ClassPanel *panel ,wxMouseEvent& event);
	virtual void onClassUp(ClassPanel *panel, wxMouseEvent& event);
	virtual void onClassMove(ClassPanel *panel, wxMouseEvent& event);

	virtual void onPanelDown(DiagramWindow* panel, wxMouseEvent& event);
	virtual void onPanelUp(DiagramWindow* panel, wxMouseEvent& event);
	virtual void onPanelMove(DiagramWindow* panel, wxMouseEvent& event);
	mauseState();
	~mauseState();
};

