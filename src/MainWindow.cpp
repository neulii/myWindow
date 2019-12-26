#include "MainWindow.h"
#include <iostream>
#include <wx/log.h>
#include "main_lib.h"

#include <fstream>

wxBEGIN_EVENT_TABLE(MainWindow, wxFrame)
	EVT_BUTTON(ID_LEFT_BUTTON, MainWindow::OnLeftButton)
	EVT_BUTTON(ID_RIGHT_BUTTON, MainWindow::OnRightButton)
wxEND_EVENT_TABLE();

MainWindow::MainWindow() :wxFrame(nullptr, wxID_ANY, "MyWindow")
{
	SetSize(wxSize(800, 600));

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
	neulib::addTextToFile("hallo das ist ein test\n","test.txt");
}

std::string MainWindow::getTextFromFile(const std::string& fileName) {
	
	return neulib::getTextFromFile(fileName);
}

void MainWindow::addTextToFile(const std::string& text, const std::string &fileName) {
	
	neulib::addTextToFile(text, fileName);
	
}

void MainWindow::OnRightButton(wxCommandEvent& event)
{
	std::string text = neulib::getTextFromFile("test.txt");
	std::cout << text;
}