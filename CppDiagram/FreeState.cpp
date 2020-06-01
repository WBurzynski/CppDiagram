#include "NoButtonPressed.h"

void NoButtonPressed::onClassDown(classPanel *panel, wxMouseEvent& evt)
{
	panel->CaptureMouse();
	panel->x = evt.GetX();
	panel->y = evt.GetY();
	panel->dragging = true;
	panel->SetBackgroundColour(wxColour(0, 0, 255));
	panel->Refresh();
}

void NoButtonPressed::onClassUp(classPanel *panel, wxMouseEvent& evt)
{
	panel->ReleaseMouse();
	panel->dragging = false;
}

void NoButtonPressed::onClassMove(classPanel *panel, wxMouseEvent& evt)
{
	if (panel->dragging)
	{
		wxPoint mouseOnScreen = wxGetMousePosition();
		int newx = mouseOnScreen.x - panel->x;
		int newy = mouseOnScreen.y - panel->y;
		panel->Move(panel->parent->ScreenToClient(wxPoint(newx, newy)));
	}
}

void NoButtonPressed::onPanelDown()
{
}

void NoButtonPressed::onPanelUp()
{
}

void NoButtonPressed::onPanelMove()
{
}
