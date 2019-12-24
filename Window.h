///////////////////////////////////////////////////////////////////////////
// C++ code generated with wxFormBuilder (version Oct 26 2018)
// http://www.wxformbuilder.org/
//
// PLEASE DO *NOT* EDIT THIS FILE!
///////////////////////////////////////////////////////////////////////////

#pragma once

#include <wx/artprov.h>
#include <wx/xrc/xmlres.h>
#include <wx/string.h>
#include <wx/stattext.h>
#include <wx/gdicmn.h>
#include <wx/font.h>
#include <wx/colour.h>
#include <wx/settings.h>
#include <wx/sizer.h>
#include <wx/textctrl.h>
#include <wx/grid.h>
#include <wx/statusbr.h>
#include <wx/bitmap.h>
#include <wx/image.h>
#include <wx/icon.h>
#include <wx/menu.h>
#include <wx/frame.h>

///////////////////////////////////////////////////////////////////////////

#define ID_PLAYER_ONE 1000
#define ID_PLAYER_TWO 1001

///////////////////////////////////////////////////////////////////////////////
/// Class Window
///////////////////////////////////////////////////////////////////////////////
class Window : public wxFrame
{
	private:

	protected:
		wxStaticText* m_winningPoints;
		wxStaticText* m_pointsPlayerOneDisplay;
		wxStaticText* m_pointsPlayerTwoDisplay;
		wxStaticText* m_playerOneNameText;
		wxStaticText* m_playerTwoNameText;
		wxTextCtrl* m_playerOneInput;
		wxTextCtrl* m_playerTwoInput;
		wxGrid* m_pointTable;
		wxStatusBar* m_statusBar;
		wxMenuBar* m_menubar;
		wxMenu* m_fileMenu;
		wxMenu* m_infoMenu;

		// Virtual event handlers, overide them in your derived class
		virtual void evt_activateWindow( wxActivateEvent& event ) { event.Skip(); }
		virtual void evt_enterInInputfield( wxCommandEvent& event ) { event.Skip(); }
		virtual void evt_NewGameClicked( wxCommandEvent& event ) { event.Skip(); }
		virtual void evt_loadFileClicked( wxCommandEvent& event ) { event.Skip(); }
		virtual void evt_saveFileClicked( wxCommandEvent& event ) { event.Skip(); }
		virtual void evt_exitProgramClicked( wxCommandEvent& event ) { event.Skip(); }
		virtual void evt_aboutClicked( wxCommandEvent& event ) { event.Skip(); }


	public:

		Window( wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = wxT("SuperSpiel"), const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize( 800,500 ), long style = wxDEFAULT_FRAME_STYLE|wxTAB_TRAVERSAL );

		~Window();

};

