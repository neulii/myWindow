#pragma once
#include "wx/wx.h"
const int ID_LEFT_BUTTON = 100;
const int ID_RIGHT_BUTTON = 200;

class MainWindow : public wxFrame
{
private:

	wxButton* m_leftButton = nullptr;
	wxButton* m_rightButton = nullptr;

public:
	MainWindow();
	~MainWindow();

	void OnLeftButton(wxCommandEvent& event);
	void OnRightButton(wxCommandEvent& event);

	std::string getTextFromFile(const std::string& fileName);
	void addTextToFile(const std::string& text, const std::string& fileName);
	
	wxDECLARE_EVENT_TABLE();
};