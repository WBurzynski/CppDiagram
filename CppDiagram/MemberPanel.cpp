#include "MemberPanel.h"

void MemberPanel::OnMauseEnter(wxMouseEvent& event)
{
	IsOverPanel = true;
	editButton->Show();
	deleteButton->Show();
	Fit();
	GetParent()->Fit();
}

void MemberPanel::OnMauseLeave(wxMouseEvent& event)
{
	IsOverPanel = false;
	if (!IsOverPanel && !IsOverButton)
	{
		editButton->Hide();
		deleteButton->Hide();
	}
	Fit();
	GetParent()->Fit();
}

void MemberPanel::OnChildMauseEnter(wxMouseEvent& event)
{
	IsOverButton = true;
}

void MemberPanel::OnChildMauseLeave(wxMouseEvent& event)
{
	IsOverButton = false;
}

void MemberPanel::onMouseDown(wxMouseEvent& event)
{
	event.ResumePropagation(1);
	event.Skip();
}

void MemberPanel::onMouseUp(wxMouseEvent& event)
{
	event.ResumePropagation(1);
	event.Skip();
}

void MemberPanel::onMove(wxMouseEvent& event)
{
	event.ResumePropagation(1);
	event.Skip();
}

MemberPanel::MemberPanel(wxWindow* parent, wxWindowID id, const wxPoint& pos, const wxSize& size, long style) : wxPanel(parent, id, pos, size, style)
{
	wxBoxSizer* bSizer1;
	bSizer1 = new wxBoxSizer(wxHORIZONTAL);

	memberText = new wxStaticText(this, wxID_ANY, wxT("MyLabel"), wxDefaultPosition, wxDefaultSize, 0);
	memberText->Wrap(-1);
	bSizer1->Add(memberText, 0, wxALL, 5);

	editButton = new wxButton(this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxSize(16, 16), 0);
	editButton->SetBitmap(wxArtProvider::GetBitmap(wxART_EDIT,wxART_OTHER, wxSize(16, 16)));
	editButton->Hide();
	bSizer1->Add(editButton, 0, wxALL, 5);

	deleteButton = new wxButton(this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxSize(16, 16), 0);
	deleteButton->SetBitmap(wxArtProvider::GetBitmap(wxART_DELETE, wxART_OTHER, wxSize(16, 16)));
	deleteButton->Hide();
	bSizer1->Add(deleteButton, 0, wxALL, 5);


	this->SetSizer(bSizer1);
	this->Layout();
	bSizer1->Fit(this);

	// Connect Events
	Bind(wxEVT_ENTER_WINDOW, &MemberPanel::OnMauseEnter, this);
	Bind(wxEVT_LEAVE_WINDOW, &MemberPanel::OnMauseLeave, this);
	
	editButton->Bind(wxEVT_COMMAND_BUTTON_CLICKED, &MemberPanel::OnEditPressed, this);
	editButton->Bind(wxEVT_ENTER_WINDOW, &MemberPanel::OnChildMauseEnter, this);
	editButton->Bind(wxEVT_LEAVE_WINDOW, &MemberPanel::OnChildMauseLeave, this);

	deleteButton->Bind(wxEVT_COMMAND_BUTTON_CLICKED, &MemberPanel::OnDeletePressed, this);
	deleteButton->Bind(wxEVT_ENTER_WINDOW, &MemberPanel::OnChildMauseEnter, this);
	deleteButton->Bind(wxEVT_LEAVE_WINDOW, &MemberPanel::OnChildMauseLeave, this);

	memberText->Bind(wxEVT_ENTER_WINDOW, &MemberPanel::OnChildMauseEnter, this);
	memberText->Bind(wxEVT_LEAVE_WINDOW, &MemberPanel::OnChildMauseLeave, this);
	memberText->Bind(wxEVT_LEFT_DOWN, &MemberPanel::onMouseDown, this);
}

MemberPanel::~MemberPanel()
{

}