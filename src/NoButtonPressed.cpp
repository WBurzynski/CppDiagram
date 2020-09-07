#include "NoButtonPressed.hpp"
#include "ClassPanel.hpp"
void NoButtonPressed::onClassDown(ClassPanel *panel, wxMouseEvent &event)
{
    panel->CaptureMouse();
    x = event.GetX();
    y = event.GetY();
    dragging = true;
    // panel->Refresh();
    event.Skip();
}

void NoButtonPressed::onClassUp(ClassPanel *panel, wxMouseEvent &event)
{
    if (panel->HasCapture())
        panel->ReleaseMouse();
    dragging = false;
    event.Skip();
}

void NoButtonPressed::onClassMove(ClassPanel *panel, wxMouseEvent &event)
{
    if (dragging)
    {
        wxPoint mouseOnScreen = wxGetMousePosition();
        panel->Move(panel->GetParent()->ScreenToClient(wxPoint(mouseOnScreen.x - x, mouseOnScreen.y - y)));
        panel->GetParent()->Refresh();
    }
    event.Skip();
}

void NoButtonPressed::onPanelDown(DiagramWindow *panel, wxMouseEvent &event)
{
}
