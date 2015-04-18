///////////////////////////////////////////////////////////////////////////
// C++ code generated with wxFormBuilder (version Dec 21 2009)
// http://www.wxformbuilder.org/
// Modified manually by Dylan Taylor.
///////////////////////////////////////////////////////////////////////////

#include "wx/wxprec.h"

#ifdef __BORLANDC__
#pragma hdrstop
#endif //__BORLANDC__

#ifndef WX_PRECOMP
#include <wx/wx.h>
#endif //WX_PRECOMP

#include "GUIFrame.h"

///////////////////////////////////////////////////////////////////////////

GUIFrame::GUIFrame( wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style ) : wxFrame( parent, id, title, pos, size, style )
{
	this->SetSizeHints( wxSize( 700,500 ), wxDefaultSize );
	this->SetBackgroundColour( wxColour( 168, 146, 113 ) );

	menuBar = new wxMenuBar( 0 );
	gameMenu = new wxMenu();
	wxMenuItem* menuGameNew;
	menuGameNew = new wxMenuItem( gameMenu, idMenuNew, wxString( wxT("&New") ) + wxT('\t') + wxT("Ctrl+N"), wxT("Start a new game"), wxITEM_NORMAL );
	gameMenu->Append( menuGameNew );

	wxMenuItem* menuGameQuit;
	menuGameQuit = new wxMenuItem( gameMenu, idMenuQuit, wxString( wxT("&Quit") ) + wxT('\t') + wxT("Ctrl+Q"), wxT("Quit playing Connect 4"), wxITEM_NORMAL );
	gameMenu->Append( menuGameQuit );

	menuBar->Append( gameMenu, wxT("&Game") );

	helpMenu = new wxMenu();
	wxMenuItem* menuHelpAbout;
	menuHelpAbout = new wxMenuItem( helpMenu, idMenuAbout, wxString( wxT("&About") ) + wxT('\t') + wxT("F1"), wxT("Show info about this application"), wxITEM_NORMAL );
	helpMenu->Append( menuHelpAbout );

	menuBar->Append( helpMenu, wxT("&Help") );

	this->SetMenuBar( menuBar );

	gameGrid = new wxGridSizer( 7, 7, 0, 0 );

	drop1 = new wxButton( this, Drop1, wxT("Drop [&1]"), wxDefaultPosition, wxDefaultSize, 0 );
	gameGrid->Add( drop1, 0, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5 );

	drop2 = new wxButton( this, Drop2, wxT("Drop [&2]"), wxDefaultPosition, wxDefaultSize, 0 );
	gameGrid->Add( drop2, 0, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5 );

	drop3 = new wxButton( this, Drop3, wxT("Drop [&3]"), wxDefaultPosition, wxDefaultSize, 0 );
	gameGrid->Add( drop3, 0, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5 );

	drop4 = new wxButton( this, Drop4, wxT("Drop [&4]"), wxDefaultPosition, wxDefaultSize, 0 );
	gameGrid->Add( drop4, 0, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5 );

	drop5 = new wxButton( this, Drop5, wxT("Drop [&5]"), wxDefaultPosition, wxDefaultSize, 0 );
	gameGrid->Add( drop5, 0, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5 );

	drop6 = new wxButton( this, Drop6, wxT("Drop [&6]"), wxDefaultPosition, wxDefaultSize, 0 );
	gameGrid->Add( drop6, 0, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5 );

	drop7 = new wxButton( this, Drop7, wxT("Drop [&7]"), wxDefaultPosition, wxDefaultSize, 0 );
	gameGrid->Add( drop7, 0, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5 );

    for (int r = 0; r < 6; r++) {
    	for (int c = 0; c < 7; c++) {
            cell[r][c] = new wxStaticBitmap( this, wxID_ANY, wxBitmap( wxT("grey.png"), wxBITMAP_TYPE_ANY ), wxDefaultPosition, wxDefaultSize, 0 );
            gameGrid->Add( cell[r][c], 0, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5 );
    	}
    }
	this->SetSizer( gameGrid );
	this->Layout();
	statusBar = this->CreateStatusBar( 2, wxST_SIZEGRIP|wxWANTS_CHARS, wxID_ANY );

	this->Centre( wxBOTH ); //Contrary to popular belief, this is NOT a typo.

	// Connect Events
	this->Connect( wxEVT_CLOSE_WINDOW, wxCloseEventHandler( GUIFrame::OnClose ) );
	this->Connect( wxEVT_KEY_DOWN, wxKeyEventHandler( GUIFrame::OnKeyPress ) );
	menuBar->Connect( wxEVT_KEY_DOWN, wxKeyEventHandler( GUIFrame::OnKeyPress ), NULL, this );
	this->Connect( menuGameNew->GetId(), wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( GUIFrame::OnNew ) );
	this->Connect( menuGameQuit->GetId(), wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( GUIFrame::OnQuit ) );
	this->Connect( menuHelpAbout->GetId(), wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( GUIFrame::OnAbout ) );
	drop1->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( GUIFrame::OnDrop1 ), NULL, this );
	drop2->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( GUIFrame::OnDrop2 ), NULL, this );
	drop3->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( GUIFrame::OnDrop3 ), NULL, this );
	drop4->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( GUIFrame::OnDrop4 ), NULL, this );
	drop5->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( GUIFrame::OnDrop5 ), NULL, this );
	drop6->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( GUIFrame::OnDrop6 ), NULL, this );
	drop7->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( GUIFrame::OnDrop7 ), NULL, this );
}

GUIFrame::~GUIFrame() {
	// Disconnect Events
	this->Disconnect( wxEVT_CLOSE_WINDOW, wxCloseEventHandler( GUIFrame::OnClose ) );
	this->Disconnect( wxEVT_KEY_DOWN, wxKeyEventHandler( GUIFrame::OnKeyPress ) );
	menuBar->Disconnect( wxEVT_KEY_DOWN, wxKeyEventHandler( GUIFrame::OnKeyPress ), NULL, this );
	this->Disconnect( wxID_ANY, wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( GUIFrame::OnNew ) );
	this->Disconnect( wxID_ANY, wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( GUIFrame::OnQuit ) );
	this->Disconnect( wxID_ANY, wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( GUIFrame::OnAbout ) );
	drop1->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( GUIFrame::OnDrop1 ), NULL, this );
	drop2->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( GUIFrame::OnDrop2 ), NULL, this );
	drop3->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( GUIFrame::OnDrop3 ), NULL, this );
	drop4->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( GUIFrame::OnDrop4 ), NULL, this );
	drop5->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( GUIFrame::OnDrop5 ), NULL, this );
	drop6->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( GUIFrame::OnDrop6 ), NULL, this );
	drop7->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( GUIFrame::OnDrop7 ), NULL, this );
}

void GUIFrame::UpdatePiece(int row, int column, wxBitmap image) {
    cell[row][column]->SetBitmap(image);
}
