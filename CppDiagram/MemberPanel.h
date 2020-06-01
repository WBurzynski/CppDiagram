#pragma once

#include "wx/artprov.h"
#include "wx/xrc/xmlres.h"
#include "wx/string.h"
#include "wx/stattext.h"
#include "wx/gdicmn.h"
#include "wx/font.h"
#include "wx/colour.h"
#include "wx/settings.h"
#include "wx/button.h"
#include "wx/sizer.h"
#include "wx/panel.h"

class MemberPanel : public wxPanel
{
private:

	bool IsOverPanel{ false };
	bool IsOverButton{ false };

protected:
	wxStaticText* memberText;
	wxButton* editButton;
	wxButton* deleteButton;


	void OnMauseEnter(wxMouseEvent& event);
	void OnMauseLeave(wxMouseEvent& event);

	virtual void OnEditPressed(wxCommandEvent& event) { event.Skip(); }
	virtual void OnDeletePressed(wxCommandEvent& event) { event.Skip(); }
	
	void OnChildMauseEnter(wxMouseEvent& event);
	void OnChildMauseLeave(wxMouseEvent& event);

public:

	MemberPanel(wxWindow* parent, wxWindowID id = wxID_ANY, const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize(-1, -1), long style = wxTAB_TRAVERSAL);
	~MemberPanel();

};