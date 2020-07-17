#include "diagramWindow.h"
#include "State.h"

#include <algorithm>
#include <fstream>

#include "wx/dcbuffer.h"

void DiagramWindow::serialize(std::ofstream& file)
{
	file << classPanels.size() << '\n';
	setIDs();
	for (auto panel : classPanels)//TODO: possibly find more expresive algorithm in STL library
	{
		panel->serialize(file);
	}
	for (auto relation : relationPanels)//TODO: possibly find more expresive algorithm in STL library
	{
		relation->serialize(file);
	}
	return;
}

void DiagramWindow::deserialize(std::ifstream& file)
{
	clear();
	int classCount;
	file >> classCount;
	for (int i = 0; i < classCount; i++)//TODO: find more expresive algorithm in STL library
	{
		classPanels.push_back(new ClassPanel(this));
		classPanels.back()->SetPosition(wxPoint(200 * i, 100));
	}
	std::for_each(classPanels.begin(), classPanels.end(), [&file](ClassPanel* panel) {panel->deserialize(file); });
	Refresh();
}

void DiagramWindow::ProcessKeyboard(wxKeyEvent& event)
{
	OnDelPressed(event);
}

void DiagramWindow::clear()//TODO: change name to more expresive
{
	for (auto panel : classPanels)//TODO: find more expresive algorithm in STL library
	{
		delete panel;
	}
	classPanels.clear();
	ClassPanel::NextID = 1;
	Refresh();
}

void DiagramWindow::setIDs()
{
	ClassPanel::NextID = 1;
	for (auto panel : classPanels)//TODO: find more expresive algorithm in STL library
	{
		panel->ID = ClassPanel::NextID++;
	}
}

DiagramWindow::DiagramWindow(wxWindow* parent, wxWindowID winid, const wxPoint & pos, const wxSize & size, long style, const wxString & name )
	: wxScrolledWindow(parent, winid, pos, size, style)
{
	wxImage::AddHandler(new wxPNGHandler);
	InheritanceArrowHead = wxImage("InheritanceArrowHead.png", wxBITMAP_TYPE_PNG);
	FriendshipArrowHead = wxImage("FriendshipArrowHead.png", wxBITMAP_TYPE_PNG);
	NestingArrowHead = wxImage("NestingArrowHead.png", wxBITMAP_TYPE_PNG);
	//Three ClassPanels for testing purposes
	//classPanels.push_back(new classPanel(this));
	//classPanels.back()->SetPosition(wxPoint(100, 100));

	//classPanels.push_back(new classPanel(this));
	//classPanels.back()->SetPosition(wxPoint(300, 100));

	//classPanels.push_back(new classPanel(this));
	//classPanels.back()->SetPosition(wxPoint(100, 300));

	SetOwnBackgroundColour(wxColour(255, 255, 255));
	Bind(wxEVT_LEFT_DOWN, &DiagramWindow::onMouseDown, this);
	Bind(wxEVT_LEFT_UP, &DiagramWindow::onMouseUp, this);
	Bind(wxEVT_MOTION, &DiagramWindow::onMove, this);
	Bind(wxEVT_PAINT, &DiagramWindow::OnPaint, this);
	Bind(wxEVT_KEY_DOWN, &DiagramWindow::OnDelPressed, this);
}

void DiagramWindow::onMouseDown(wxMouseEvent& event)
{
	State::get()->onPanelDown(this, event);
}

void DiagramWindow::onMouseUp(wxMouseEvent& event)
{
	State::get()->onPanelUp(this, event);
}

void DiagramWindow::onMove(wxMouseEvent& event)
{
	State::get()->onPanelMove(this, event);
}

void DiagramWindow::OnDelPressed(wxKeyEvent& event)
{
	static bool s = false;
		if (s)
			SetBackgroundColour(wxColour(0, 0, 0));
		else
			SetBackgroundColour(wxColour(255, 255, 255));
		s = !s;
		Refresh();
}

void DiagramWindow::OnPaint(wxPaintEvent& event)
{
	wxPaintDC dc(this);
	for (auto relation : relationPanels)
	{
		relation->setLines();
	}
}