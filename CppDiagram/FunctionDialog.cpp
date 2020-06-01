#include "FunctionDialog.h"

void FunctionDialog::OnModifierPicked(wxCommandEvent& event)
{
	switch (event.GetSelection())
	{
	case 0://"normal" radio button
		data.modifier = dgFunction::Modifier::dgNone;
		break;
	case 1://"static" radio button
		data.modifier = dgFunction::Modifier::dgStatic;
		break;
	case 2://"virtual" radio button
		data.modifier = dgFunction::Modifier::dgVirtual;
		break;
	}
}

void FunctionDialog::OnVisibilityPicked(wxCommandEvent& event)
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

void FunctionDialog::OnAddClicked(wxCommandEvent& event)
{
	addArgument();
}

void FunctionDialog::addArgument()
{
	arguments.push_back(new ArgumentPanel(this->ArgumentsWindow));
	ArgumentsSizer->Add(arguments.back(), wxEXPAND | wxALL, 0);
	ArgumentsWindow->SetVirtualSize(ArgumentsWindow->GetBestVirtualSize());
	Fit();
}

void FunctionDialog::addArgument(dgArgument var)
{
	arguments.push_back(new ArgumentPanel(this->ArgumentsWindow, var));
	ArgumentsSizer->Add(arguments.back(), wxEXPAND | wxALL, 0);
	ArgumentsWindow->SetVirtualSize(ArgumentsWindow->GetBestVirtualSize());
	Fit();
}

void FunctionDialog::OnRemoveClick(wxCommandEvent& event)
{
	ArgumentsSizer->Remove(ArgumentsSizer->GetItemCount() - 1);
	delete arguments.back();
	arguments.pop_back();
	ArgumentsWindow->SetVirtualSize(ArgumentsWindow->GetBestVirtualSize());
	Fit();
}

void FunctionDialog::OnCancel(wxCommandEvent& event)
{
	EndModal(wxID_CANCEL);
}

void FunctionDialog::OnOK(wxCommandEvent& event)
{
	for (auto arg : arguments)
	{
		data.addArgument(arg->GetValue());
	}
	data.name = NameTextCtrl->GetLineText(0).ToStdString();
	data.type = TypeTextCtrl->GetLineText(0).ToStdString();
	EndModal(wxID_OK);
}

dgFunction FunctionDialog::GetValue()
{
	return data;
}

FunctionDialog::FunctionDialog(wxWindow* parent) : FunctionDialogLayout(parent), data("","")
{

}

FunctionDialog::FunctionDialog(wxWindow* parent, dgFunction func) : FunctionDialogLayout(parent), data(func)
{
	for (dgArgument arg : func.arguments)
	{
		addArgument(arg);
	}
	NameTextCtrl->SetLabel(func.name);
	TypeTextCtrl->SetLabel(func.type);

	switch (func.modifier)
	{
	case dgFunction::Modifier::dgNone:
		ModifierBox->SetSelection(0);
		break;
	case dgFunction::Modifier::dgStatic:
		ModifierBox->SetSelection(1);
		break;
	case dgFunction::Modifier::dgVirtual:
		ModifierBox->SetSelection(2);
		break;
	}

	switch (func.visibility)
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
