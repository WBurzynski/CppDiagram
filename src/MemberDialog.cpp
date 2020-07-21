///////////////////////////////////////////////////////////////////////////
// C++ code generated with wxFormBuilder (version Jun 17 2015)
// http://www.wxformbuilder.org/
//
// PLEASE DO "NOT" EDIT THIS FILE!
///////////////////////////////////////////////////////////////////////////

#include "MemberDialog.hpp"

///////////////////////////////////////////////////////////////////////////

MemberDialog::MemberDialog( wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style ) : wxDialog( parent, id, title, pos, size, style )
{
	this->SetSizeHints( wxSize( -1,-1 ), wxDefaultSize );

	wxBoxSizer* bSizer6;
	bSizer6 = new wxBoxSizer( wxVERTICAL );

	DescriptionText = new wxStaticText( this, wxID_ANY, wxT("Insert member info:"), wxDefaultPosition, wxDefaultSize, 0 );
	DescriptionText->Wrap( -1 );
	bSizer6->Add( DescriptionText, 0, wxALL, 5 );

	wxGridBagSizer* gbSizer1;
	gbSizer1 = new wxGridBagSizer( 0, 0 );
	gbSizer1->SetFlexibleDirection( wxBOTH );
	gbSizer1->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );

	TypeText = new wxStaticText( this, wxID_ANY, wxT("Type:"), wxDefaultPosition, wxDefaultSize, 0 );
	TypeText->Wrap( -1 );
	gbSizer1->Add( TypeText, wxGBPosition( 0, 0 ), wxGBSpan( 1, 1 ), wxALL, 5 );

	NameText = new wxStaticText( this, wxID_ANY, wxT("Name:"), wxDefaultPosition, wxDefaultSize, 0 );
	NameText->Wrap( -1 );
	gbSizer1->Add( NameText, wxGBPosition( 0, 1 ), wxGBSpan( 1, 1 ), wxALL, 5 );

	TypeTextCtrl = new wxTextCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	gbSizer1->Add( TypeTextCtrl, wxGBPosition( 1, 0 ), wxGBSpan( 1, 1 ), wxALL|wxEXPAND, 5 );

	NameTextCtrl = new wxTextCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	gbSizer1->Add( NameTextCtrl, wxGBPosition( 1, 1 ), wxGBSpan( 1, 1 ), wxALL|wxEXPAND, 5 );

	wxString ModifierBoxChoices[] = { wxT("Normal"), wxT("Static"), wxT("Mutable") };
	int ModifierBoxNChoices = sizeof( ModifierBoxChoices ) / sizeof( wxString );
	ModifierBox = new wxRadioBox( this, wxID_ANY, wxT("Modifier"), wxDefaultPosition, wxDefaultSize, ModifierBoxNChoices, ModifierBoxChoices, 1, wxRA_SPECIFY_ROWS );
	ModifierBox->SetSelection( 0 );
	gbSizer1->Add( ModifierBox, wxGBPosition( 2, 0 ), wxGBSpan( 1, 2 ), wxALL|wxEXPAND, 5 );

	wxString VisibilityBoxChoices[] = { wxT("Public"), wxT("Protected"), wxT("Private") };
	int VisibilityBoxNChoices = sizeof( VisibilityBoxChoices ) / sizeof( wxString );
	VisibilityBox = new wxRadioBox( this, wxID_ANY, wxT("Visibility"), wxDefaultPosition, wxDefaultSize, VisibilityBoxNChoices, VisibilityBoxChoices, 1, wxRA_SPECIFY_ROWS );
	VisibilityBox->SetSelection( 0 );
	gbSizer1->Add( VisibilityBox, wxGBPosition( 3, 0 ), wxGBSpan( 1, 2 ), wxALL, 5 );

	m_staticline2 = new wxStaticLine( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxLI_HORIZONTAL );
	gbSizer1->Add( m_staticline2, wxGBPosition( 4, 0 ), wxGBSpan( 1, 3 ), wxEXPAND | wxALL, 5 );


	bSizer6->Add( gbSizer1, 4, wxEXPAND, 5 );

	m_sdbSizer3 = new wxStdDialogButtonSizer();
	m_sdbSizer3OK = new wxButton( this, wxID_OK );
	m_sdbSizer3->AddButton( m_sdbSizer3OK );
	m_sdbSizer3Cancel = new wxButton( this, wxID_CANCEL );
	m_sdbSizer3->AddButton( m_sdbSizer3Cancel );
	m_sdbSizer3->Realize();

	bSizer6->Add( m_sdbSizer3, 1, wxEXPAND, 5 );


	this->SetSizer( bSizer6 );
	this->Layout();
	bSizer6->Fit( this );

	this->Centre( wxBOTH );

	// Connect Events
	ModifierBox->Connect( wxEVT_COMMAND_RADIOBOX_SELECTED, wxCommandEventHandler( MemberDialog::OnModifierPicked ), NULL, this );
	VisibilityBox->Connect( wxEVT_COMMAND_RADIOBOX_SELECTED, wxCommandEventHandler( MemberDialog::OnVisibilityPicked ), NULL, this );
	m_sdbSizer3Cancel->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( MemberDialog::OnCancel ), NULL, this );
	m_sdbSizer3OK->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( MemberDialog::OnOk ), NULL, this );
}

MemberDialog::~MemberDialog()
{
	// Disconnect Events
	ModifierBox->Disconnect( wxEVT_COMMAND_RADIOBOX_SELECTED, wxCommandEventHandler( MemberDialog::OnModifierPicked ), NULL, this );
	VisibilityBox->Disconnect( wxEVT_COMMAND_RADIOBOX_SELECTED, wxCommandEventHandler( MemberDialog::OnVisibilityPicked ), NULL, this );
	m_sdbSizer3Cancel->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( MemberDialog::OnCancel ), NULL, this );
	m_sdbSizer3OK->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( MemberDialog::OnOk ), NULL, this );

}
