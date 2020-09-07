///////////////////////////////////////////////////////////////////////////
// C++ code generated with wxFormBuilder (version Jun 17 2015)
// http://www.wxformbuilder.org/
//
// PLEASE DO "NOT" EDIT THIS FILE!
///////////////////////////////////////////////////////////////////////////

#include "FunctionDialogLayout.hpp"

///////////////////////////////////////////////////////////////////////////

FunctionDialogLayout::FunctionDialogLayout(wxWindow *parent, wxWindowID id, const wxString &title, const wxPoint &pos,
                                           const wxSize &size, long style)
    : wxDialog(parent, id, title, pos, size, style)
{
    this->SetSizeHints(wxDefaultSize, wxDefaultSize);

    wxBoxSizer *bSizer1;
    bSizer1 = new wxBoxSizer(wxVERTICAL);

    DescriptionText =
        new wxStaticText(this, wxID_ANY, wxT("Insert member function info:"), wxDefaultPosition, wxDefaultSize, 0);
    DescriptionText->Wrap(-1);
    bSizer1->Add(DescriptionText, 0, wxALL, 5);

    wxGridBagSizer *gbSizer1;
    gbSizer1 = new wxGridBagSizer(0, 0);
    gbSizer1->SetFlexibleDirection(wxBOTH);
    gbSizer1->SetNonFlexibleGrowMode(wxFLEX_GROWMODE_SPECIFIED);

    TypeText = new wxStaticText(this, wxID_ANY, wxT("Type:"), wxDefaultPosition, wxDefaultSize, 0);
    TypeText->Wrap(-1);
    gbSizer1->Add(TypeText, wxGBPosition(0, 0), wxGBSpan(1, 1), wxALL | wxEXPAND, 5);

    NameText = new wxStaticText(this, wxID_ANY, wxT("Name:"), wxDefaultPosition, wxDefaultSize, 0);
    NameText->Wrap(-1);
    gbSizer1->Add(NameText, wxGBPosition(0, 1), wxGBSpan(1, 1), wxALL | wxEXPAND, 5);

    TypeTextCtrl = new wxTextCtrl(this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0);
    gbSizer1->Add(TypeTextCtrl, wxGBPosition(1, 0), wxGBSpan(1, 1), wxALL | wxEXPAND, 5);

    NameTextCtrl = new wxTextCtrl(this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0);
    gbSizer1->Add(NameTextCtrl, wxGBPosition(1, 1), wxGBSpan(1, 1), wxALL | wxEXPAND, 5);

    wxString ModifierBoxChoices[] = {wxT("Normal"), wxT("Static"), wxT("Virtual")};
    int ModifierBoxNChoices = sizeof(ModifierBoxChoices) / sizeof(wxString);
    ModifierBox = new wxRadioBox(this, wxID_ANY, wxT("Modifier"), wxDefaultPosition, wxDefaultSize, ModifierBoxNChoices,
                                 ModifierBoxChoices, 1, wxRA_SPECIFY_ROWS);
    ModifierBox->SetSelection(0);
    gbSizer1->Add(ModifierBox, wxGBPosition(2, 0), wxGBSpan(1, 2), wxALL | wxEXPAND, 5);

    wxString VisibilityBoxChoices[] = {wxT("Public"), wxT("Protected"), wxT("Private")};
    int VisibilityBoxNChoices = sizeof(VisibilityBoxChoices) / sizeof(wxString);
    VisibilityBox = new wxRadioBox(this, wxID_ANY, wxT("Visibility"), wxDefaultPosition, wxDefaultSize,
                                   VisibilityBoxNChoices, VisibilityBoxChoices, 1, wxRA_SPECIFY_ROWS);
    VisibilityBox->SetSelection(0);
    gbSizer1->Add(VisibilityBox, wxGBPosition(3, 0), wxGBSpan(1, 2), wxALL | wxEXPAND, 5);

    AddButton = new wxButton(this, wxID_ANY, wxT("Add argument"), wxDefaultPosition, wxDefaultSize, 0);
    gbSizer1->Add(AddButton, wxGBPosition(4, 0), wxGBSpan(1, 1), wxALL, 5);

    RemoveButton = new wxButton(this, wxID_ANY, wxT("Remove argument"), wxDefaultPosition, wxDefaultSize, 0);
    gbSizer1->Add(RemoveButton, wxGBPosition(4, 1), wxGBSpan(1, 1), wxALL, 5);

    bSizer1->Add(gbSizer1, 5, wxEXPAND, 5);

    ArgumentsWindow =
        new wxScrolledWindow(this, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxALWAYS_SHOW_SB | wxVSCROLL);
    ArgumentsWindow->SetScrollRate(0, 5);
    ArgumentsSizer = new wxBoxSizer(wxVERTICAL);

    ArgumentsWindow->SetSizer(ArgumentsSizer);
    ArgumentsWindow->Layout();
    ArgumentsSizer->Fit(ArgumentsWindow);
    bSizer1->Add(ArgumentsWindow, 2, wxEXPAND | wxALL, 5);

    m_sdbSizer1 = new wxStdDialogButtonSizer();
    m_sdbSizer1OK = new wxButton(this, wxID_OK);
    m_sdbSizer1->AddButton(m_sdbSizer1OK);
    m_sdbSizer1Cancel = new wxButton(this, wxID_CANCEL);
    m_sdbSizer1->AddButton(m_sdbSizer1Cancel);
    m_sdbSizer1->Realize();

    bSizer1->Add(m_sdbSizer1, 1, wxEXPAND, 5);

    this->SetSizer(bSizer1);
    this->Layout();
    bSizer1->Fit(this);

    this->Centre(wxBOTH);

    // Connect Events
    ModifierBox->Connect(wxEVT_COMMAND_RADIOBOX_SELECTED, wxCommandEventHandler(FunctionDialogLayout::OnModifierPicked),
                         NULL, this);
    VisibilityBox->Connect(wxEVT_COMMAND_RADIOBOX_SELECTED,
                           wxCommandEventHandler(FunctionDialogLayout::OnVisibilityPicked), NULL, this);
    AddButton->Connect(wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(FunctionDialogLayout::OnAddClicked), NULL,
                       this);
    RemoveButton->Connect(wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(FunctionDialogLayout::OnRemoveClick),
                          NULL, this);
    m_sdbSizer1Cancel->Connect(wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(FunctionDialogLayout::OnCancel),
                               NULL, this);
    m_sdbSizer1OK->Connect(wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(FunctionDialogLayout::OnOK), NULL, this);
}

FunctionDialogLayout::~FunctionDialogLayout()
{
    // Disconnect Events
    ModifierBox->Disconnect(wxEVT_COMMAND_RADIOBOX_SELECTED,
                            wxCommandEventHandler(FunctionDialogLayout::OnModifierPicked), NULL, this);
    VisibilityBox->Disconnect(wxEVT_COMMAND_RADIOBOX_SELECTED,
                              wxCommandEventHandler(FunctionDialogLayout::OnVisibilityPicked), NULL, this);
    AddButton->Disconnect(wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(FunctionDialogLayout::OnAddClicked), NULL,
                          this);
    RemoveButton->Disconnect(wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(FunctionDialogLayout::OnRemoveClick),
                             NULL, this);
    m_sdbSizer1Cancel->Disconnect(wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(FunctionDialogLayout::OnCancel),
                                  NULL, this);
    m_sdbSizer1OK->Disconnect(wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(FunctionDialogLayout::OnOK), NULL,
                              this);
}
