#include "MainFrame.h"

#include "fstream"

#include "State.h"
MainFrame::MainFrame(wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style) : frameLayout(parent, id, title, pos, size, style)
{
	//TODO: Add possibility to change size of canvas
	canvas->SetVirtualSize(wxSize(2000, 2000));
	State::set(State::NoButton, nullptr);
	Center();
	Show();
}

MainFrame::~MainFrame()
{

}

void MainFrame::ToggleButtons(wxObject* source)
{
	std::for_each(buttons.begin(), buttons.end(), [source](wxToggleButton* button)
		{
			if (button != source) button->SetValue(false);
		});
}


void MainFrame::OnKeyDown(wxKeyEvent& event)
{
	canvas->ProcessKeyboard(event);
}

void MainFrame::OnNewSelected(wxCommandEvent& event)
{
	if (true)//if current content has not been saved TODO: Replace true with checking memento pattern
	{
		if (wxMessageBox(_("Unsaved changes will be lost. Do you want to continue?"), _("C++ Diagram editor"),
			wxICON_QUESTION | wxYES_NO, this) == wxNO)
			return;
	}
	canvas->clear();
}

void MainFrame::OnOpenSelected(wxCommandEvent& event)
{
	if (true)//if current content has not been saved TODO: Replace true with checking memento pattern
	{
		if (wxMessageBox(_("Unsaved changes will be lost. Do you want to continue?"), _("C++ Diagram editor"),
			wxICON_QUESTION | wxYES_NO, this) == wxNO)
			return;
	}

	wxFileDialog openFileDialog(this, _("Open cppdg file"), "", "",
		"cppdg files (*.cppdg)|*.cppdg", wxFD_OPEN | wxFD_FILE_MUST_EXIST);
	if (openFileDialog.ShowModal() == wxID_CANCEL)
		return;

	std::ifstream file(openFileDialog.GetPath().ToStdString());
	if (file.good())
	{
		canvas->clear();
		canvas->deserialize(file);
	}
	file.close();
}

void MainFrame::OnSaveSelected(wxCommandEvent& event)
{
	wxFileDialog saveFileDialog(this, wxT("Save XYZ file"), "", "",
		"XYZ files (*.xyz)|*.xyz", wxFD_SAVE | wxFD_OVERWRITE_PROMPT);
	if (saveFileDialog.ShowModal() == wxID_CANCEL)
		return;

	std::ofstream file(saveFileDialog.GetPath().ToStdString());
	if (file.good())
		canvas->serialize(file);
	file.close();
}

void MainFrame::OnAuthorSelected(wxCommandEvent& event)
{
	//TODO: Add content
	event.Skip();
}

void MainFrame::OnSourceSelected(wxCommandEvent& event)
{
	//TODO: Add content
	event.Skip();
}

void MainFrame::OnClassToggled(wxCommandEvent& event)
{
	ToggleButtons(event.GetEventObject());

	State::set(State::ClassButton, (wxToggleButton*)event.GetEventObject());

	SetStatusText(wxT("Class Toggled"));
}

void MainFrame::OnDataToggled(wxCommandEvent& event)
{
	ToggleButtons(event.GetEventObject());

	State::set(State::DataButton, (wxToggleButton*)event.GetEventObject());

	SetStatusText(wxT("Data Toggled"));
}

void MainFrame::OnFunctionToggled(wxCommandEvent& event)
{
	ToggleButtons(event.GetEventObject());

	State::set(State::FunctionButton, (wxToggleButton*)event.GetEventObject());

	SetStatusText(wxT("Function Toggled"));
}

void MainFrame::OnInheritanceToggled(wxCommandEvent& event)
{
	ToggleButtons(event.GetEventObject());

	State::set(State::InheritanceButton, (wxToggleButton*)event.GetEventObject());

	SetStatusText(wxT("Inheritance Toggled"));
}

void MainFrame::OnFriendshipToggled(wxCommandEvent& event)
{
	ToggleButtons(event.GetEventObject());

	State::set(State::FriendshipButton, (wxToggleButton*)event.GetEventObject());

	SetStatusText(wxT("Friendship Toggled"));
}

void MainFrame::OnNestingToggled(wxCommandEvent& event)
{
	ToggleButtons(event.GetEventObject());

	State::set(State::NestingButton, (wxToggleButton*)event.GetEventObject());

	SetStatusText(wxT("Nesting Toggled"));
}
