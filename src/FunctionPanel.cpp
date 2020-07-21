#include "FunctionPanel.hpp"
#include "ClassPanel.hpp"
#include "FunctionDialog.hpp"
void FunctionPanel::OnEditPressed(wxCommandEvent& event)
{
	FunctionDialog* editMemberDialog = new FunctionDialog(this->GetParent(), data);
	if (editMemberDialog->ShowModal() == wxID_OK)
	{
		//TODO: Check if user entered valid name
		data = editMemberDialog->GetValue();
		memberText->SetLabel(data.getDeclaration());
		if (data.modifier == dgFunction::Modifier::dgStatic)
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

void FunctionPanel::OnDeletePressed(wxCommandEvent& event)
{
	reinterpret_cast<ClassPanel*>(GetParent())->removeMember(this);
}

FunctionPanel::FunctionPanel(wxWindow* parent, dgFunction _data) : MemberPanel(parent), data(_data)
{
	memberText->SetLabel(data.getDeclaration());
	if (data.modifier == dgFunction::Modifier::dgStatic)
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
