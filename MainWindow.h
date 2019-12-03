#pragma once
#include "wx/wx.h"
const int ID_LEFT_BUTTON = 100;
const int ID_RIGHT_BUTTON = 200;

template <typename T>
void printAnyThing(T anyThing)
{
	//if T is an integer
	if (typeid(T) == typeid(int)) {

		std::cout << "type is int: " << anyThing << std::endl;
	}
	//if T is anything else type
	else
	{
		std::cout << anyThing << std::endl;
	}
}

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