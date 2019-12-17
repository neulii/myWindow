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
#include <wx/bitmap.h>
#include <wx/image.h>
#include <wx/icon.h>
#include <wx/button.h>
#include <wx/grid.h>
#include <wx/frame.h>

///////////////////////////////////////////////////////////////////////////


///////////////////////////////////////////////////////////////////////////////
/// Class Window
///////////////////////////////////////////////////////////////////////////////
class Window : public wxFrame
{
	private:

	protected:
		wxStaticText* m_pointsPlayerOneDisplay;
		wxStaticText* m_pointsPlayerTwoDisplay;
		wxStaticText* m_playerOne;
		wxStaticText* m_playerTwo;
		wxTextCtrl* m_playerOneInput;
		wxTextCtrl* m_playerTwoInput;
		wxButton* m_EnterInput;
		wxGrid* m_pointTable;

		// Virtual event handlers, overide them in your derived class
		virtual void m_EnterInputClick( wxCommandEvent& event ) { event.Skip(); }


	public:

		Window( wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = wxT("SuperSpiel"), const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize( 800,500 ), long style = wxDEFAULT_FRAME_STYLE|wxTAB_TRAVERSAL );

		~Window();

};
