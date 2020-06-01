#include "mauseState.h"

void mauseState::onClassDown(ClassPanel *panel, wxMouseEvent& event)
{
	event.Skip();
}

void mauseState::onClassUp(ClassPanel *panel, wxMouseEvent& event)
{
	event.Skip();
}

void mauseState::onClassMove(ClassPanel *panel, wxMouseEvent& event)
{
	event.Skip();
}

void mauseState::onPanelDown(DiagramWindow* panel, wxMouseEvent& event)
{
	event.Skip();
}

void mauseState::onPanelUp(DiagramWindow* panel, wxMouseEvent& event)
{
	event.Skip();
}

void mauseState::onPanelMove(DiagramWindow* panel, wxMouseEvent& event)
{
	event.Skip();
}

mauseState::mauseState()
{
}

mauseState::~mauseState()
{
}
