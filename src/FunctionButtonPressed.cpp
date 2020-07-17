#include "FunctionButtonPressed.h"
#include "ClassPanel.h"
#include "diagramWindow.h"
#include "State.h"
#include <wx/tglbtn.h>
#include "FunctionDialog.h"
void FunctionButtonPressed::onClassDown(ClassPanel* panel, wxMouseEvent& event)
{
	FunctionDialog* newMemberDialog = new FunctionDialog(panel->GetParent());

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

void FunctionButtonPressed::onPanelDown(DiagramWindow* panel, wxMouseEvent& event)
{
	//TODO: play error sound and/or show message dialog
	event.Skip();
}

FunctionButtonPressed::FunctionButtonPressed()
{
}

FunctionButtonPressed::~FunctionButtonPressed()
{
}
