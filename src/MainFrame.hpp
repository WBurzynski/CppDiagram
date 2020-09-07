#pragma once

#include <vector>

#include "wx/wx.h"
#include "frameLayout.hpp"

using std::vector;

class MainFrame : public frameLayout
{
	vector<wxToggleButton*> buttons{ classButton, dataButton, functionButton, inheritanceButton, friendshipButton, nestingButton };

	void OnKeyDown(wxKeyEvent& event) override;
	void OnNewSelected(wxCommandEvent& event) override;
	void OnOpenSelected(wxCommandEvent& event) override;
	void OnSaveSelected(wxCommandEvent& event) override;
	void OnExportSelected(wxCommandEvent& event) override;
	void OnAuthorSelected(wxCommandEvent& event) override;
	void OnSourceSelected(wxCommandEvent& event) override;
	void OnClassToggled(wxCommandEvent& event) override;
	void OnDataToggled(wxCommandEvent& event) override;
	void OnFunctionToggled(wxCommandEvent& event) override;
	void OnInheritanceToggled(wxCommandEvent& event) override;
	void OnFriendshipToggled(wxCommandEvent& event) override;
	void OnNestingToggled(wxCommandEvent& event) override;
public:

	MainFrame( wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = wxT("Class Designer"), const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize( 978,465 ), long style = wxDEFAULT_FRAME_STYLE|wxTAB_TRAVERSAL );
	~MainFrame();

	void ToggleButtons(wxObject* source);

};
