#include "ClassButtonPressed.h"

#include "wx/textdlg.h"

#include "classPanel.h"
#include "diagramWindow.h"
#include "State.h"

void ClassButtonPressed::onClassDown(ClassPanel* panel, wxMouseEvent& event)
{
	onPanelDown((DiagramWindow*)panel->GetParent(), event);
}

void ClassButtonPressed::onPanelDown(DiagramWindow* panel, wxMouseEvent& event)
{
	wxTextEntryDialog* newClassDialog = new wxTextEntryDialog(panel->GetParent(),"Insert Class name","New Class","MyClass");
	
	if (newClassDialog->ShowModal() == wxID_OK)
	{
		//TODO: Check if user entered valid name

		panel->classPanels.push_back(new ClassPanel(panel, newClassDialog->GetValue().ToStdString()));
		panel->classPanels.back()->SetPosition(event.GetPosition());
		panel->Refresh();
		State::getSource()->SetValue(false);
		State::set(State::NoButton, nullptr);
	}
}