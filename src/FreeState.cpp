#include "NoButtonPressed.hpp"
#include "ClassPanel.hpp"
void NoButtonPressed::onClassDown(ClassPanel *panel, wxMouseEvent& evt)
{
	panel->CaptureMouse();
	x = evt.GetX();
	y = evt.GetY();
	dragging = true;
	panel->SetBackgroundColour(wxColour(0, 0, 255));
	panel->Refresh();
}

void NoButtonPressed::onClassUp(ClassPanel *panel, wxMouseEvent& evt)
{
	panel->ReleaseMouse();
	dragging = false;
}

void NoButtonPressed::onClassMove(ClassPanel *panel, wxMouseEvent& evt)
{
	if (dragging)
	{
		wxPoint mouseOnScreen = wxGetMousePosition();
		int newx = mouseOnScreen.x - x;
		int newy = mouseOnScreen.y - y;
		panel->Move(panel->GetParent()->ScreenToClient(wxPoint(newx, newy)));
	}
}

void NoButtonPressed::onPanelDown(DiagramWindow* panel, wxMouseEvent& event)
{
}
