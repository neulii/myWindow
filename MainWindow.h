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

	wxDECLARE_EVENT_TABLE();



};

