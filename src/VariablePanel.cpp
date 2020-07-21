#include "VariablePanel.hpp"
#include "ClassPanel.hpp"
#include "DataMemberDialog.hpp"
void VariablePanel::OnEditPressed(wxCommandEvent& event)
{
	DataMemberDialog* editMemberDialog = new DataMemberDialog(this->GetParent(), data);
	if (editMemberDialog->ShowModal() == wxID_OK)
	{
		//TODO: Check if user entered valid name
		data = editMemberDialog->GetValue();
		memberText->SetLabel(data.getDeclaration());
		if (data.modifier == dgVariable::Modifier::dgStatic)
		{
			wxFont font = memberText->GetFont();
			font.SetUnderlined(true);
			memberText->SetFont(font);
		}
		else
		{
			wxFont font = memberText->GetFont();
			font.SetUnderlined(false);
			memberText->SetFont(font);
		}
	}
}

void VariablePanel::OnDeletePressed(wxCommandEvent& event)
{
	reinterpret_cast<ClassPanel*>(GetParent())->removeMember(this);
}

VariablePanel::VariablePanel(wxWindow* parent, dgVariable _data) : MemberPanel(parent), data(_data)
{
	memberText->SetLabel(data.getDeclaration());
	if (data.modifier == dgVariable::Modifier::dgStatic)
	{
		wxFont font = memberText->GetFont();
		font.SetUnderlined(true);
		memberText->SetFont(font);
	}
	else
	{
		wxFont font = memberText->GetFont();
		font.SetUnderlined(false);
		memberText->SetFont(font);
	}
}
