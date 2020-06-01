#include "App.h"
#include "MainFrame.h"

wxIMPLEMENT_APP(App);

bool App::OnInit()
{
	MainFrame* frame = new MainFrame(NULL, wxID_ANY, wxT("Class Designer"), wxDefaultPosition, wxSize(640, 480));

	return true;
}