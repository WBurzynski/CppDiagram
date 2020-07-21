#pragma once

#include <vector>

#include "wx/wx.h"
#include "frameLayout.hpp"

using std::vector;

class MainFrame : public frameLayout
{
	vector<wxToggleButton*> buttons{ classButton, dataButton, functionButton, inheritanceButton, friendshipButton, nestingButton };

	void OnKeyDown(wxKeyEvent& event);
	void OnNewSelected(wxCommandEvent& event);
	void OnOpenSelected(wxCommandEvent& event);
	void OnSaveSelected(wxCommandEvent& event);
	void OnAuthorSelected(wxCommandEvent& event);
	void OnSourceSelected(wxCommandEvent& event);
	void OnClassToggled(wxCommandEvent& event);
	void OnDataToggled(wxCommandEvent& event);
	void OnFunctionToggled(wxCommandEvent& event);
	void OnInheritanceToggled(wxCommandEvent& event);
	void OnFriendshipToggled(wxCommandEvent& event);
	void OnNestingToggled(wxCommandEvent& event);
public:

	MainFrame( wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = wxT("Class Designer"), const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize( 978,465 ), long style = wxDEFAULT_FRAME_STYLE|wxTAB_TRAVERSAL );
	~MainFrame();

	void ToggleButtons(wxObject* source);

};
