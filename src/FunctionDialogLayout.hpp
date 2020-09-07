///////////////////////////////////////////////////////////////////////////
// C++ code generated with wxFormBuilder (version Jun 17 2015)
// http://www.wxformbuilder.org/
//
// PLEASE DO "NOT" EDIT THIS FILE!
///////////////////////////////////////////////////////////////////////////

#ifndef __FUNCTIONDIALOGLAYOUT_H__
#define __FUNCTIONDIALOGLAYOUT_H__

#include <wx/artprov.h>
#include <wx/button.h>
#include <wx/colour.h>
#include <wx/dialog.h>
#include <wx/font.h>
#include <wx/gbsizer.h>
#include <wx/gdicmn.h>
#include <wx/radiobox.h>
#include <wx/scrolwin.h>
#include <wx/settings.h>
#include <wx/sizer.h>
#include <wx/stattext.h>
#include <wx/string.h>
#include <wx/textctrl.h>
#include <wx/xrc/xmlres.h>

///////////////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////////////
/// Class FunctionDialogLayout
///////////////////////////////////////////////////////////////////////////////
class FunctionDialogLayout : public wxDialog
{
  private:
  protected:
    wxStaticText *DescriptionText;
    wxStaticText *TypeText;
    wxStaticText *NameText;
    wxTextCtrl *TypeTextCtrl;
    wxTextCtrl *NameTextCtrl;
    wxRadioBox *ModifierBox;
    wxRadioBox *VisibilityBox;
    wxButton *AddButton;
    wxButton *RemoveButton;
    wxScrolledWindow *ArgumentsWindow;
    wxBoxSizer *ArgumentsSizer;
    wxStdDialogButtonSizer *m_sdbSizer1;
    wxButton *m_sdbSizer1OK;
    wxButton *m_sdbSizer1Cancel;

    // Virtual event handlers, overide them in your derived class
    virtual void OnModifierPicked(wxCommandEvent &event)
    {
        event.Skip();
    }
    virtual void OnVisibilityPicked(wxCommandEvent &event)
    {
        event.Skip();
    }
    virtual void OnAddClicked(wxCommandEvent &event)
    {
        event.Skip();
    }
    virtual void OnRemoveClick(wxCommandEvent &event)
    {
        event.Skip();
    }
    virtual void OnCancel(wxCommandEvent &event)
    {
        event.Skip();
    }
    virtual void OnOK(wxCommandEvent &event)
    {
        event.Skip();
    }

  public:
    FunctionDialogLayout(wxWindow *parent, wxWindowID id = wxID_ANY, const wxString &title = wxEmptyString,
                         const wxPoint &pos = wxDefaultPosition, const wxSize &size = wxDefaultSize,
                         long style = wxDEFAULT_DIALOG_STYLE);
    ~FunctionDialogLayout();
};

#endif //__FUNCTIONDIALOGLAYOUT_H__
