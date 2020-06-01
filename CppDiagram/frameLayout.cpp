///////////////////////////////////////////////////////////////////////////
// C++ code generated with wxFormBuilder (version Jun 17 2015)
// http://www.wxformbuilder.org/
//
// PLEASE DO "NOT" EDIT THIS FILE!
///////////////////////////////////////////////////////////////////////////

#include "frameLayout.h"

///////////////////////////////////////////////////////////////////////////

frameLayout::frameLayout( wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style ) : wxFrame( parent, id, title, pos, size, style )
{
	this->SetSizeHints( wxDefaultSize, wxDefaultSize );
	
	m_menubar1 = new wxMenuBar( 0 );
	fileMenu = new wxMenu();
	wxMenuItem* newMenuItem;
	newMenuItem = new wxMenuItem( fileMenu, wxID_ANY, wxString( wxT("New") ) , wxEmptyString, wxITEM_NORMAL );
	fileMenu->Append( newMenuItem );
	
	wxMenuItem* openMenuItem;
	openMenuItem = new wxMenuItem( fileMenu, wxID_ANY, wxString( wxT("Open") ) , wxEmptyString, wxITEM_NORMAL );
	fileMenu->Append( openMenuItem );
	
	wxMenuItem* saveMenuItem;
	saveMenuItem = new wxMenuItem( fileMenu, wxID_ANY, wxString( wxT("Save") ) , wxEmptyString, wxITEM_NORMAL );
	fileMenu->Append( saveMenuItem );
	
	m_menubar1->Append( fileMenu, wxT("File") ); 
	
	aboutMenu = new wxMenu();
	wxMenuItem* authorMenuItem;
	authorMenuItem = new wxMenuItem( aboutMenu, wxID_ANY, wxString( wxT("Author") ) , wxEmptyString, wxITEM_NORMAL );
	aboutMenu->Append( authorMenuItem );
	
	wxMenuItem* sourceMenuItem;
	sourceMenuItem = new wxMenuItem( aboutMenu, wxID_ANY, wxString( wxT("Factual sources") ) , wxEmptyString, wxITEM_NORMAL );
	aboutMenu->Append( sourceMenuItem );
	
	m_menubar1->Append( aboutMenu, wxT("About") ); 
	
	this->SetMenuBar( m_menubar1 );
	
	wxBoxSizer* frameSizer;
	frameSizer = new wxBoxSizer( wxHORIZONTAL );
	
	controlWindow = new wxScrolledWindow( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxVSCROLL );
	controlWindow->SetScrollRate( 5, 5 );
	controlWindow->SetMinSize( wxSize( 150,-1 ) );
	
	wxBoxSizer* controlSizer;
	controlSizer = new wxBoxSizer( wxVERTICAL );
	
	classesText = new wxStaticText( controlWindow, wxID_ANY, wxT("Classes"), wxDefaultPosition, wxDefaultSize, wxALIGN_CENTRE );
	classesText->Wrap( -1 );
	controlSizer->Add( classesText, 0, wxALL|wxEXPAND, 5 );
	
	classButton = new wxToggleButton( controlWindow, wxID_ANY, wxT("Class"), wxDefaultPosition, wxDefaultSize, 0 );
	controlSizer->Add( classButton, 0, wxALL|wxEXPAND, 5 );
	
	m_staticline2 = new wxStaticLine( controlWindow, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxLI_HORIZONTAL );
	controlSizer->Add( m_staticline2, 0, wxEXPAND | wxALL, 5 );
	
	membersText = new wxStaticText( controlWindow, wxID_ANY, wxT("Members"), wxDefaultPosition, wxDefaultSize, wxALIGN_CENTRE );
	membersText->Wrap( -1 );
	controlSizer->Add( membersText, 0, wxALL|wxEXPAND, 5 );
	
	dataButton = new wxToggleButton( controlWindow, wxID_ANY, wxT("Data member "), wxDefaultPosition, wxDefaultSize, 0 );
	controlSizer->Add( dataButton, 0, wxALL|wxEXPAND, 5 );
	
	functionButton = new wxToggleButton( controlWindow, wxID_ANY, wxT("Member function"), wxDefaultPosition, wxDefaultSize, 0 );
	controlSizer->Add( functionButton, 0, wxALL|wxEXPAND, 5 );
	
	m_staticline3 = new wxStaticLine( controlWindow, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxLI_HORIZONTAL );
	controlSizer->Add( m_staticline3, 0, wxEXPAND | wxALL, 5 );
	
	relationshipsText = new wxStaticText( controlWindow, wxID_ANY, wxT("Relationships"), wxDefaultPosition, wxDefaultSize, wxALIGN_CENTRE );
	relationshipsText->Wrap( -1 );
	controlSizer->Add( relationshipsText, 0, wxALL|wxEXPAND, 5 );
	
	inheritanceButton = new wxToggleButton( controlWindow, wxID_ANY, wxT("Inheritance"), wxDefaultPosition, wxDefaultSize, 0 );
	controlSizer->Add( inheritanceButton, 0, wxALL|wxEXPAND, 5 );
	
	friendshipButton = new wxToggleButton( controlWindow, wxID_ANY, wxT("Friendship"), wxDefaultPosition, wxDefaultSize, 0 );
	controlSizer->Add( friendshipButton, 0, wxALL|wxEXPAND, 5 );
	
	nestingButton = new wxToggleButton( controlWindow, wxID_ANY, wxT("Nesting"), wxDefaultPosition, wxDefaultSize, 0 );
	controlSizer->Add( nestingButton, 0, wxALL|wxEXPAND, 5 );
	
	
	controlWindow->SetSizer( controlSizer );
	controlWindow->Layout();
	controlSizer->Fit( controlWindow );
	frameSizer->Add( controlWindow, 1, wxEXPAND, 5 );
	
	canvas = new DiagramWindow( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxHSCROLL|wxVSCROLL );
	canvas->SetScrollRate( 5, 5 );
	frameSizer->Add( canvas, 4, wxALL|wxEXPAND, 5 );
	
	
	this->SetSizer( frameSizer );
	this->Layout();
	statusBar = this->CreateStatusBar( 1, wxST_SIZEGRIP, wxID_ANY );
	
	this->Centre( wxBOTH );
	
	// Connect Events
	this->Connect( wxEVT_KEY_DOWN, wxKeyEventHandler( frameLayout::OnKeyDown ) );
	this->Connect( newMenuItem->GetId(), wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( frameLayout::OnNewSelected ) );
	this->Connect( openMenuItem->GetId(), wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( frameLayout::OnOpenSelected ) );
	this->Connect( saveMenuItem->GetId(), wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( frameLayout::OnSaveSelected ) );
	this->Connect( authorMenuItem->GetId(), wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( frameLayout::OnAuthorSelected ) );
	this->Connect( sourceMenuItem->GetId(), wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( frameLayout::OnSourceSelected ) );
	classButton->Connect( wxEVT_COMMAND_TOGGLEBUTTON_CLICKED, wxCommandEventHandler( frameLayout::OnClassToggled ), NULL, this );
	dataButton->Connect( wxEVT_COMMAND_TOGGLEBUTTON_CLICKED, wxCommandEventHandler( frameLayout::OnDataToggled ), NULL, this );
	functionButton->Connect( wxEVT_COMMAND_TOGGLEBUTTON_CLICKED, wxCommandEventHandler( frameLayout::OnFunctionToggled ), NULL, this );
	inheritanceButton->Connect( wxEVT_COMMAND_TOGGLEBUTTON_CLICKED, wxCommandEventHandler( frameLayout::OnInheritanceToggled ), NULL, this );
	friendshipButton->Connect( wxEVT_COMMAND_TOGGLEBUTTON_CLICKED, wxCommandEventHandler( frameLayout::OnFriendshipToggled ), NULL, this );
	nestingButton->Connect( wxEVT_COMMAND_TOGGLEBUTTON_CLICKED, wxCommandEventHandler( frameLayout::OnNestingToggled ), NULL, this );
}

frameLayout::~frameLayout()
{
	// Disconnect Events
	this->Disconnect( wxEVT_KEY_DOWN, wxKeyEventHandler( frameLayout::OnKeyDown ) );
	this->Disconnect( wxID_ANY, wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( frameLayout::OnNewSelected ) );
	this->Disconnect( wxID_ANY, wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( frameLayout::OnOpenSelected ) );
	this->Disconnect( wxID_ANY, wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( frameLayout::OnSaveSelected ) );
	this->Disconnect( wxID_ANY, wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( frameLayout::OnAuthorSelected ) );
	this->Disconnect( wxID_ANY, wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( frameLayout::OnSourceSelected ) );
	classButton->Disconnect( wxEVT_COMMAND_TOGGLEBUTTON_CLICKED, wxCommandEventHandler( frameLayout::OnClassToggled ), NULL, this );
	dataButton->Disconnect( wxEVT_COMMAND_TOGGLEBUTTON_CLICKED, wxCommandEventHandler( frameLayout::OnDataToggled ), NULL, this );
	functionButton->Disconnect( wxEVT_COMMAND_TOGGLEBUTTON_CLICKED, wxCommandEventHandler( frameLayout::OnFunctionToggled ), NULL, this );
	inheritanceButton->Disconnect( wxEVT_COMMAND_TOGGLEBUTTON_CLICKED, wxCommandEventHandler( frameLayout::OnInheritanceToggled ), NULL, this );
	friendshipButton->Disconnect( wxEVT_COMMAND_TOGGLEBUTTON_CLICKED, wxCommandEventHandler( frameLayout::OnFriendshipToggled ), NULL, this );
	nestingButton->Disconnect( wxEVT_COMMAND_TOGGLEBUTTON_CLICKED, wxCommandEventHandler( frameLayout::OnNestingToggled ), NULL, this );
	
}
