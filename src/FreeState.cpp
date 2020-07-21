#include "NoButtonPressed.hpp"
#include "ClassPanel.hpp"
void NoButtonPressed::onClassDown(ClassPanel *panel, wxMouseEvent& evt)
{
	panel->CaptureMouse();
	panel->x = evt.GetX();
	panel->y = evt.GetY();
	panel->dragging = true;
	panel->SetBackgroundColour(wxColour(0, 0, 255));
	panel->Refresh();
}

void NoButtonPressed::onClassUp(ClassPanel *panel, wxMouseEvent& evt)
{
	panel->ReleaseMouse();
	panel->dragging = false;
}

void NoButtonPressed::onClassMove(ClassPanel *panel, wxMouseEvent& evt)
{
	if (panel->dragging)
	{
		wxPoint mouseOnScreen = wxGetMousePosition();
		int newx = mouseOnScreen.x - panel->x;
		int newy = mouseOnScreen.y - panel->y;
		panel->Move(panel->parent->ScreenToClient(wxPoint(newx, newy)));
	}
}

void NoButtonPressed::onPanelDown(DiagramWindow* panel, wxMouseEvent& event)
{
}

void NoButtonPressed::onPanelUp(DiagramWindow* panel, wxMouseEvent& event)
{
}

void NoButtonPressed::onPanelMove(DiagramWindow* panel, wxMouseEvent& event)
{
}
