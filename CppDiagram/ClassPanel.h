#pragma once

#include "wx/wx.h"
#include "wx/statline.h"

#include <string>
#include <vector>

#include "FunctionPanel.h"
#include "VariablePanel.h"

using std::string;
using std::vector;

class ClassPanel : public wxPanel
{
public:
	enum mode
	{
		newFunction,
		newVariable
	};
private:

	wxBoxSizer *MainSizer, *DataSizer, *FunctionSizer;
	wxStaticText* ClassName;
	wxStaticLine* m_staticline1;
	vector<FunctionPanel*> memberFunctions;
	wxStaticLine* m_staticline2;
	vector<VariablePanel*> memberVariables;
	
	static int NextID;
	int ID;
	

	void onMouseDown(wxMouseEvent& event);
	void onMouseUp(wxMouseEvent& event);
	void onMove(wxMouseEvent& event);
public:
	//TODO: Make those vectors and pointer private
	//vector<classPanel*> parents;
	//vector<classPanel*> friends;
	//classPanel* outer{ nullptr };

	int getID() const;
	void addMember(dgFunction fun);
	void addMember(dgVariable var);

	void removeMember(FunctionPanel* fun);
	void removeMember(VariablePanel* var);

	void serialize(std::ofstream &file);
	void deserialize(std::ifstream& file);

	ClassPanel(wxPanel* parent, string name = "MyClass");

	friend class DiagramWindow;
};

