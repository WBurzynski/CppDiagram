#include "DataButtonPressed.hpp"
#include "ClassPanel.hpp"
#include "diagramWindow.hpp"
#include "State.hpp"
#include "wx/tglbtn.h"
#include "DataMemberDialog.hpp"
void DataButtonPressed::onClassDown(ClassPanel* panel, wxMouseEvent& event)
{
	DataMemberDialog* newMemberDialog = new DataMemberDialog(panel->GetParent());

	if (newMemberDialog->ShowModal() == wxID_OK)
	{
		//TODO: Check if user entered valid name
		auto data = newMemberDialog->GetValue();
		panel->addMember(data);

		panel->Refresh();
	}
	State::getSource()->SetValue(false);
	State::set(State::NoButton, nullptr);
}

void DataButtonPressed::onPanelDown(DiagramWindow* panel, wxMouseEvent& event)
{
	//TODO: play error sound and/or show message dialog
	event.Skip();
}

