///////////////////////////////////////////////////////////////////////////
// C++ code generated with wxFormBuilder (version Oct 26 2018)
// http://www.wxformbuilder.org/
//
// PLEASE DO *NOT* EDIT THIS FILE!
///////////////////////////////////////////////////////////////////////////

#include "Window.h"

///////////////////////////////////////////////////////////////////////////

Window::Window( wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style ) : wxFrame( parent, id, title, pos, size, style )
{
	this->SetSizeHints( wxDefaultSize, wxDefaultSize );

	wxBoxSizer* bSizer4;
	bSizer4 = new wxBoxSizer( wxHORIZONTAL );

	wxBoxSizer* bSizer11;
	bSizer11 = new wxBoxSizer( wxVERTICAL );

	wxBoxSizer* bSizer16;
	bSizer16 = new wxBoxSizer( wxHORIZONTAL );

	m_pointsPlayerOneDisplay = new wxStaticText( this, wxID_ANY, wxT("0"), wxDefaultPosition, wxSize( 100,-1 ), wxALIGN_CENTER_HORIZONTAL );
	m_pointsPlayerOneDisplay->Wrap( -1 );
	m_pointsPlayerOneDisplay->SetFont( wxFont( 18, wxFONTFAMILY_DEFAULT, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_BOLD, false, wxEmptyString ) );

	bSizer16->Add( m_pointsPlayerOneDisplay, 0, wxALL, 5 );

	m_pointsPlayerTwoDisplay = new wxStaticText( this, wxID_ANY, wxT("0"), wxDefaultPosition, wxSize( 100,-1 ), wxALIGN_CENTER_HORIZONTAL );
	m_pointsPlayerTwoDisplay->Wrap( -1 );
	m_pointsPlayerTwoDisplay->SetFont( wxFont( 18, wxFONTFAMILY_DEFAULT, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_BOLD, false, wxEmptyString ) );

	bSizer16->Add( m_pointsPlayerTwoDisplay, 1, wxALL|wxEXPAND, 5 );


	bSizer11->Add( bSizer16, 0, 0, 5 );

	wxBoxSizer* bSizer15;
	bSizer15 = new wxBoxSizer( wxHORIZONTAL );

	m_playerOne = new wxStaticText( this, wxID_ANY, wxT("PlayerOne"), wxDefaultPosition, wxDefaultSize, wxALIGN_CENTER_HORIZONTAL );
	m_playerOne->Wrap( -1 );
	m_playerOne->SetMinSize( wxSize( 100,-1 ) );

	bSizer15->Add( m_playerOne, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );

	m_playerTwo = new wxStaticText( this, wxID_ANY, wxT("PlayerTwo"), wxDefaultPosition, wxDefaultSize, wxALIGN_CENTER_HORIZONTAL );
	m_playerTwo->Wrap( -1 );
	m_playerTwo->SetMinSize( wxSize( 100,-1 ) );

	bSizer15->Add( m_playerTwo, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );


	bSizer11->Add( bSizer15, 0, 0, 5 );

	wxBoxSizer* bSizer13;
	bSizer13 = new wxBoxSizer( wxHORIZONTAL );

	m_playerOneInput = new wxTextCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	m_playerOneInput->SetMinSize( wxSize( 100,-1 ) );

	bSizer13->Add( m_playerOneInput, 0, wxALL, 5 );

	m_playerTwoInput = new wxTextCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	m_playerTwoInput->SetMinSize( wxSize( 100,-1 ) );

	bSizer13->Add( m_playerTwoInput, 0, wxALL, 5 );


	bSizer11->Add( bSizer13, 0, 0, 5 );

	wxBoxSizer* bSizer14;
	bSizer14 = new wxBoxSizer( wxVERTICAL );

	m_EnterInput = new wxButton( this, wxID_ANY, wxT("Punkte Eintragen"), wxDefaultPosition, wxDefaultSize, 0 );
	m_EnterInput->SetMinSize( wxSize( 210,-1 ) );

	bSizer14->Add( m_EnterInput, 0, wxALL, 5 );


	bSizer11->Add( bSizer14, 0, wxEXPAND, 5 );


	bSizer4->Add( bSizer11, 1, wxEXPAND, 5 );

	wxBoxSizer* bSizer12;
	bSizer12 = new wxBoxSizer( wxVERTICAL );

	m_pointTable = new wxGrid( this, wxID_ANY, wxDefaultPosition, wxSize( 300,-1 ), 0 );

	// Grid
	m_pointTable->CreateGrid( 1, 2 );
	m_pointTable->EnableEditing( false );
	m_pointTable->EnableGridLines( true );
	m_pointTable->EnableDragGridSize( false );
	m_pointTable->SetMargins( 0, 0 );

	// Columns
	m_pointTable->SetColSize( 0, 65 );
	m_pointTable->SetColSize( 1, 65 );
	m_pointTable->EnableDragColMove( false );
	m_pointTable->EnableDragColSize( false );
	m_pointTable->SetColLabelSize( 30 );
	m_pointTable->SetColLabelAlignment( wxALIGN_CENTER, wxALIGN_CENTER );

	// Rows
	m_pointTable->EnableDragRowSize( false );
	m_pointTable->SetRowLabelSize( 50 );
	m_pointTable->SetRowLabelAlignment( wxALIGN_CENTER, wxALIGN_CENTER );

	// Label Appearance

	// Cell Defaults
	m_pointTable->SetDefaultCellAlignment( wxALIGN_CENTER, wxALIGN_CENTER );
	m_pointTable->SetMinSize( wxSize( 200,-1 ) );

	bSizer12->Add( m_pointTable, 0, wxALL, 5 );


	bSizer4->Add( bSizer12, 1, wxEXPAND, 5 );


	this->SetSizer( bSizer4 );
	this->Layout();

	this->Centre( wxBOTH );

	// Connect Events
	m_EnterInput->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( Window::m_EnterInputClick ), NULL, this );
}

Window::~Window()
{
	// Disconnect Events
	m_EnterInput->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( Window::m_EnterInputClick ), NULL, this );

}
