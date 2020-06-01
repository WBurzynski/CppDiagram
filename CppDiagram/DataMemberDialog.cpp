#include "DataMemberDialog.h"
#include "wx/msgdlg.h"
void DataMemberDialog::OnModifierPicked(wxCommandEvent& event)
{
	switch (event.GetSelection())
	{
	case 0://"normal" radio button
		data.modifier = dgVariable::Modifier::dgNone;
		break;
	case 1://"static" radio button
		data.modifier = dgVariable::Modifier::dgStatic;
		break;
	case 2://"mutable" radio button
		data.modifier = dgVariable::Modifier::dgMutable;
		break;
	}
}

void DataMemberDialog::OnVisibilityPicked(wxCommandEvent& event)
{
	switch (event.GetSelection())
	{
	case 0://"public" radio button
		data.visibility = dgVisibility::dgPublic;
		break;
	case 1://"protected" radio button
		data.visibility = dgVisibility::dgProtected;
		break;
	case 2://"private" radio button
		data.visibility = dgVisibility::dgPrivate;
		break;
	}
}

void DataMemberDialog::OnCancel(wxCommandEvent& event)
{
	EndModal(wxID_CANCEL);
}

void DataMemberDialog::OnOk(wxCommandEvent& event)
{
	data.name = NameTextCtrl->GetLineText(0).ToStdString();
	data.type = TypeTextCtrl->GetLineText(0).ToStdString();
	EndModal(wxID_OK);
}

dgVariable DataMemberDialog::GetValue()
{
	return data;
}

DataMemberDialog::DataMemberDialog(wxWindow* parent) : MemberDialog(parent), data("","")
{

}

DataMemberDialog::DataMemberDialog(wxWindow* parent, dgVariable var) : MemberDialog(parent), data(var)
{
	NameTextCtrl->SetLabel(var.name);
	TypeTextCtrl->SetLabel(var.type);

	switch (var.modifier)
	{
	case dgVariable::Modifier::dgNone:
		ModifierBox->SetSelection(0);
		break;
	case dgVariable::Modifier::dgStatic:
		ModifierBox->SetSelection(1);
		break;
	case dgVariable::Modifier::dgMutable:
		ModifierBox->SetSelection(2);
		break;
	}

	switch (var.visibility)
	{
	case dgVisibility::dgPublic:
		VisibilityBox->SetSelection(0);
		break;
	case dgVisibility::dgProtected:
		VisibilityBox->SetSelection(1);
		break;
	case dgVisibility::dgPrivate:
		VisibilityBox->SetSelection(2);
		break;
	}
}
