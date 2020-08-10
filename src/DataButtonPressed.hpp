#pragma once

#include "wx/textdlg.h"

#include "mauseState.hpp"
class ClassPanel;
class DiagramWindow;
class DataButtonPressed : public mauseState
{
	void onClassDown(ClassPanel* panel, wxMouseEvent& event) override;

	void onPanelDown(DiagramWindow* panel, wxMouseEvent& event) override;
};

