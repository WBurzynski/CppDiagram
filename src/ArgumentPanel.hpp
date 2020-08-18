#pragma once
//TODO: change <> to ""
#include <wx/artprov.h>
#include <wx/xrc/xmlres.h>
#include <wx/string.h>
#include <wx/stattext.h>
#include <wx/gdicmn.h>
#include <wx/font.h>
#include <wx/colour.h>
#include <wx/settings.h>
#include <wx/textctrl.h>
#include <wx/sizer.h>
#include <wx/statline.h>
#include <wx/panel.h>

#include <string>

#include "dgArgument.hpp"

using std::string;
///
///Some doc
///
class ArgumentPanel : public wxPanel
{
private:
	static int NextID;
	int ID;
protected:
	wxStaticText* ArgumentNumber;
	wxStaticText* TypeText;
	//TODO: Correct name
	wxStaticText* NametText;
	wxStaticText* ValueText;
	wxTextCtrl* TypeTextCtrl;
	wxTextCtrl* NameTextCtrl;
	wxTextCtrl* ValueTextCtrl;

public:

	dgArgument data;
	dgArgument GetValue();

	ArgumentPanel(wxWindow* parent, wxWindowID id = wxID_ANY, const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize(-1, -1), long style = wxBORDER_THEME);
	ArgumentPanel(wxWindow* parent, dgArgument function, wxWindowID id = wxID_ANY, const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize(-1, -1), long style = wxBORDER_THEME);
	~ArgumentPanel();

};
