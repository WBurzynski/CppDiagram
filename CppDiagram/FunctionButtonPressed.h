#pragma once
#include "wx/event.h"

#include "mauseState.h"

class ClassPanel;
class DiagramWindow;
class FunctionButtonPressed : public mauseState
{
public:
	virtual void onClassDown(ClassPanel* panel, wxMouseEvent& event) override;

	virtual void onPanelDown(DiagramWindow* panel, wxMouseEvent& event) override;
	FunctionButtonPressed();
	~FunctionButtonPressed();
};



