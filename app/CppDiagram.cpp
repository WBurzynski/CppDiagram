#include "MainFrame.hpp"
#include "wx/wx.h"

class App : public wxApp
{

  public:
    virtual bool OnInit();
};

wxIMPLEMENT_APP(App);

bool App::OnInit()
{
    MainFrame *frame = new MainFrame(nullptr, wxID_ANY, wxT("Class Designer"), wxDefaultPosition, wxSize(640, 480),
                                     wxDEFAULT_FRAME_STYLE | wxTAB_TRAVERSAL);
    return true;
}
