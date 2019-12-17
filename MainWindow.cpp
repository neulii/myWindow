#include "MainWindow.h"
#include <iostream>
#include <wx/log.h>

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
	addTextToFile("hallo das ist ein test\n","test.txt");

}

std::string MainWindow::getTextFromFile(const std::string& fileName) {

	std::string inputText;
	std::string line;
	
	std::ifstream input;

	input.open(fileName, std::ios_base::in);
	
	while (std::getline(input, line)) {
		inputText = inputText + "\n" + line;
	}



	input.close();

	return  inputText;
}

void MainWindow::addTextToFile(const std::string& text, const std::string &fileName) {
	
	std::ofstream output;

	output.open(fileName, std::ios_base::out | std::ios_base::app);

	if (output.is_open()) {
		output << text;
		output.close();
		std::cout << std::endl << "Text written to File" << std::endl;
	}

	else {
		std::cout << "Error by Opening File" << std::endl;
	}

}

void MainWindow::OnRightButton(wxCommandEvent& event)
{
	std::string text = getTextFromFile("test.txt");
	std::cout << text;
}