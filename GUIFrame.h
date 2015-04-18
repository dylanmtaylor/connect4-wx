///////////////////////////////////////////////////////////////////////////
// C++ code generated with wxFormBuilder (version Dec 21 2009)
// http://www.wxformbuilder.org/
// Manually modified by Dylan Taylor
///////////////////////////////////////////////////////////////////////////

#ifndef __GUIFrame__
#define __GUIFrame__

#include <wx/string.h>
#include <wx/bitmap.h>
#include <wx/image.h>
#include <wx/icon.h>
#include <wx/menu.h>
#include <wx/gdicmn.h>
#include <wx/font.h>
#include <wx/colour.h>
#include <wx/settings.h>
#include <wx/button.h>
#include <wx/statbmp.h>
#include <wx/sizer.h>
#include <wx/statusbr.h>
#include <wx/frame.h>

///////////////////////////////////////////////////////////////////////////

#define idMenuNew 1000
#define idMenuQuit 1001
#define idMenuAbout 1002
#define Drop1 1003
#define Drop2 1004
#define Drop3 1005
#define Drop4 1006
#define Drop5 1007
#define Drop6 1008
#define Drop7 1009

///////////////////////////////////////////////////////////////////////////////
/// Class GUIFrame
///////////////////////////////////////////////////////////////////////////////
class GUIFrame : public wxFrame
{
	private:

	protected:
		wxMenuBar* menuBar;
		wxMenu* gameMenu;
		wxMenu* helpMenu;
		wxButton* drop1;
		wxButton* drop2;
		wxButton* drop3;
		wxButton* drop4;
		wxButton* drop5;
		wxButton* drop6;
		wxButton* drop7;
		wxStatusBar* statusBar;

		// Virtual event handlers, overide them in your derived class
		virtual void OnClose( wxCloseEvent& event ) { event.Skip(); }
		virtual void OnKeyPress( wxKeyEvent& event ) { event.Skip(); }
		virtual void OnNew( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnQuit( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnAbout( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnDrop1( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnDrop2( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnDrop3( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnDrop4( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnDrop5( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnDrop6( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnDrop7( wxCommandEvent& event ) { event.Skip(); }

	public:
        wxGridSizer* gameGrid;
		wxStaticBitmap* cell[6][7]; //rows, cols
		GUIFrame( wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = wxT("Connect Four"), const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize( 700,600 ), long style = wxDEFAULT_FRAME_STYLE|wxTAB_TRAVERSAL );
		~GUIFrame();
		void UpdatePiece(int row, int column, wxBitmap image);
};

#endif //__GUIFrame__
