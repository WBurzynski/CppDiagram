#pragma once

#include <vector>

#include "wx\scrolwin.h"


#include "ClassPanel.h"
#include "RelationPanel.h"

using std::vector;

class DiagramWindow : public wxScrolledWindow
{
public:
	enum relation
	{
		newDerriving,
		newFriendship,
		newNesting
	};
private:
	wxImage InheritanceArrowHead;
	wxImage FriendshipArrowHead;
	wxImage NestingArrowHead;

	vector<ClassPanel*> classPanels;
	//vector<RelationPanel*> RelationPanels;

	void OnDelPressed(wxKeyEvent& event);
	void onMouseDown(wxMouseEvent& event);
	void onMouseUp(wxMouseEvent& event);
	void onMove(wxMouseEvent& event);
	void OnPaint(wxPaintEvent& event);

public:
	void serialize(std::ofstream& file);
	void deserialize(std::ifstream& file);
	void ProcessKeyboard(wxKeyEvent& event);
	void clear();
	void setIDs();
	DiagramWindow(wxWindow* parent, wxWindowID winid = -1, const wxPoint & pos = wxDefaultPosition, const wxSize & size = wxDefaultSize, long style = -1073741824L, const wxString & name = wxPanelNameStr);
	vector<RelationPanel*> relationPanels;//TODO: make it private

	//TODO: Get rid of friend declarations
	friend RelationPanel::RelationPanel(ClassPanel* _first, ClassPanel* _second, relationType _type);
	friend class NoButtonPressed;
	friend class ClassButtonPressed;
	friend class DataButtonPressed;
};

