#include "MainWindow.h"
#include <iostream>
#include <wx/log.h>

wxBEGIN_EVENT_TABLE(MainWindow, wxFrame)
	EVT_BUTTON(ID_LEFT_BUTTON, MainWindow::OnLeftButton)
	EVT_BUTTON(ID_RIGHT_BUTTON, MainWindow::OnRightButton)
wxEND_EVENT_TABLE();

MainWindow::MainWindow() :wxFrame(nullptr, wxID_ANY, "MyWindow")
{
	SetSize(wxSize(500, 400));

	//center my window

	m_leftButton = new wxButton(this, ID_LEFT_BUTTON, "Click me", wxPoint(20, 20), wxSize(120, 35));
	m_rightButton = new wxButton(this, ID_RIGHT_BUTTON, "Click me", wxPoint(150, 20), wxSize(120, 35));

	Center();

	//m_logWindow->Show(true);
}

MainWindow::~MainWindow()
{

}

void MainWindow::OnLeftButton(wxCommandEvent& event)
{
	printAnyThing(44);
}

void MainWindow::OnRightButton(wxCommandEvent& event)
{
	std::cout << "das ist ein gedrückter button" << std::endl;
}