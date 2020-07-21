#include "ArgumentPanel.hpp"

dgArgument ArgumentPanel::GetValue()
{
	data.name = NameTextCtrl->GetLineText(0).ToStdString();
	data.type = TypeTextCtrl->GetLineText(0).ToStdString();
	data.defaultValue = ValueTextCtrl->GetLineText(0).ToStdString();
	return data;
}

ArgumentPanel::ArgumentPanel(wxWindow* parent, wxWindowID id, const wxPoint& pos, const wxSize& size, long style) : wxPanel(parent, id, pos, size, style), data("","")
{
	ID = NextID++;
	//ArgumentPanel::NextID++;
	wxFlexGridSizer* fgSizer1;
	fgSizer1 = new wxFlexGridSizer(0, 3, 0, 0);
	fgSizer1->SetFlexibleDirection(wxBOTH);
	fgSizer1->SetNonFlexibleGrowMode(wxFLEX_GROWMODE_SPECIFIED);

	ArgumentNumber = new wxStaticText(this, wxID_ANY, "Argument "+ std::to_string(ID)+":", wxDefaultPosition, wxDefaultSize, 0);
	ArgumentNumber->Wrap(-1);
	fgSizer1->Add(ArgumentNumber, 0, wxALL, 5);


	fgSizer1->Add(0, 0, 1, wxEXPAND, 5);


	fgSizer1->Add(0, 0, 1, wxEXPAND, 5);

	TypeText = new wxStaticText(this, wxID_ANY, wxT("Type:"), wxDefaultPosition, wxDefaultSize, 0);
	TypeText->Wrap(-1);
	fgSizer1->Add(TypeText, 0, wxALL, 5);

	NametText = new wxStaticText(this, wxID_ANY, wxT("Name:"), wxDefaultPosition, wxDefaultSize, 0);
	NametText->Wrap(-1);
	fgSizer1->Add(NametText, 0, wxALL, 5);

	ValueText = new wxStaticText(this, wxID_ANY, wxT("Default value:"), wxDefaultPosition, wxDefaultSize, 0);
	ValueText->Wrap(-1);
	fgSizer1->Add(ValueText, 0, wxALL, 5);

	TypeTextCtrl = new wxTextCtrl(this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0);
	fgSizer1->Add(TypeTextCtrl, 0, wxALL | wxEXPAND, 5);

	NameTextCtrl = new wxTextCtrl(this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0);
	fgSizer1->Add(NameTextCtrl, 0, wxALL | wxEXPAND, 5);

	ValueTextCtrl = new wxTextCtrl(this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0);
	fgSizer1->Add(ValueTextCtrl, 0, wxALL | wxEXPAND, 5);


	this->SetSizer(fgSizer1);
	this->Layout();
	fgSizer1->Fit(this);
}

ArgumentPanel::ArgumentPanel(wxWindow* parent, dgArgument var, wxWindowID id, const wxPoint& pos, const wxSize& size, long style) : ArgumentPanel(parent)
{
	TypeTextCtrl->SetLabel(var.type);
	NameTextCtrl->SetLabel(var.name);
	ValueTextCtrl->SetLabel(var.defaultValue);
}

ArgumentPanel::~ArgumentPanel()
{
	ArgumentPanel::NextID--;
}
int ArgumentPanel::NextID = 0;
