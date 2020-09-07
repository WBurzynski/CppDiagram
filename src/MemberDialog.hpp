///////////////////////////////////////////////////////////////////////////
// C++ code generated with wxFormBuilder (version Jun 17 2015)
// http://www.wxformbuilder.org/
//
// PLEASE DO "NOT" EDIT THIS FILE!
///////////////////////////////////////////////////////////////////////////

#ifndef __MEMBERDIALOG_H__
#define __MEMBERDIALOG_H__

#include <wx/artprov.h>
#include <wx/button.h>
#include <wx/colour.h>
#include <wx/dialog.h>
#include <wx/font.h>
#include <wx/gbsizer.h>
#include <wx/gdicmn.h>
#include <wx/radiobox.h>
#include <wx/settings.h>
#include <wx/sizer.h>
#include <wx/statline.h>
#include <wx/stattext.h>
#include <wx/string.h>
#include <wx/textctrl.h>
#include <wx/xrc/xmlres.h>

///////////////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////////////
/// Class MemberDialog
///////////////////////////////////////////////////////////////////////////////
class MemberDialog : public wxDialog
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
    wxStaticLine *m_staticline2;
    wxStdDialogButtonSizer *m_sdbSizer3;
    wxButton *m_sdbSizer3OK;
    wxButton *m_sdbSizer3Cancel;

    // Virtual event handlers, overide them in your derived class
    virtual void OnModifierPicked(wxCommandEvent &event)
    {
        event.Skip();
    }
    virtual void OnVisibilityPicked(wxCommandEvent &event)
    {
        event.Skip();
    }
    virtual void OnCancel(wxCommandEvent &event)
    {
        event.Skip();
    }
    virtual void OnOk(wxCommandEvent &event)
    {
        event.Skip();
    }

  public:
    MemberDialog(wxWindow *parent, wxWindowID id = wxID_ANY, const wxString &title = wxEmptyString,
                 const wxPoint &pos = wxDefaultPosition, const wxSize &size = wxSize(-1, -1),
                 long style = wxDEFAULT_DIALOG_STYLE);
    ~MemberDialog();
};

#endif //__MEMBERDIALOG_H__
