///////////////////////////////////////////////////////////////////////////
// C++ code generated with wxFormBuilder (version Jun 17 2015)
// http://www.wxformbuilder.org/
//
// PLEASE DO "NOT" EDIT THIS FILE!
///////////////////////////////////////////////////////////////////////////

#ifndef __FRAMELAYOUT_H__
#define __FRAMELAYOUT_H__

#include <wx/artprov.h>
#include <wx/xrc/xmlres.h>
#include <wx/string.h>
#include <wx/bitmap.h>
#include <wx/image.h>
#include <wx/icon.h>
#include <wx/menu.h>
#include <wx/gdicmn.h>
#include <wx/font.h>
#include <wx/colour.h>
#include <wx/settings.h>
#include <wx/stattext.h>
#include <wx/tglbtn.h>
#include <wx/statline.h>
#include <wx/sizer.h>
#include <wx/scrolwin.h>
#include "diagramWindow.hpp"
#include <wx/statusbr.h>
#include <wx/frame.h>

///////////////////////////////////////////////////////////////////////////


///////////////////////////////////////////////////////////////////////////////
/// Class frameLayout
///////////////////////////////////////////////////////////////////////////////
class frameLayout : public wxFrame
{
	private:

	protected:
		wxMenuBar* m_menubar1;
		wxMenu* fileMenu;
		wxMenu* aboutMenu;
		wxScrolledWindow* controlWindow;
		wxStaticText* classesText;
		wxToggleButton* classButton;
		wxStaticLine* m_staticline2;
		wxStaticText* membersText;
		wxToggleButton* dataButton;
		wxToggleButton* functionButton;
		wxStaticLine* m_staticline3;
		wxStaticText* relationshipsText;
		wxToggleButton* inheritanceButton;
		wxToggleButton* friendshipButton;
		wxToggleButton* nestingButton;
		DiagramWindow *canvas;
		wxStatusBar* statusBar;

		// Virtual event handlers, overide them in your derived class
		virtual void OnKeyDown( wxKeyEvent& event ) = 0;
		virtual void OnNewSelected( wxCommandEvent& event ) = 0;
		virtual void OnOpenSelected( wxCommandEvent& event ) = 0;
		virtual void OnSaveSelected( wxCommandEvent& event ) = 0;
		virtual void OnExportSelected( wxCommandEvent& event ) = 0;
		virtual void OnAuthorSelected( wxCommandEvent& event ) = 0;
		virtual void OnSourceSelected( wxCommandEvent& event ) = 0;
		virtual void OnClassToggled( wxCommandEvent& event ) = 0;
		virtual void OnDataToggled( wxCommandEvent& event ) = 0;
		virtual void OnFunctionToggled( wxCommandEvent& event ) = 0;
		virtual void OnInheritanceToggled( wxCommandEvent& event ) = 0;
		virtual void OnFriendshipToggled( wxCommandEvent& event ) = 0;
		virtual void OnNestingToggled( wxCommandEvent& event ) = 0;


	public:

		frameLayout( wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = wxT("Class Designer"), const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize( 978,465 ), long style = wxDEFAULT_FRAME_STYLE|wxTAB_TRAVERSAL );

		~frameLayout();

};

#endif //__FRAMELAYOUT_H__
