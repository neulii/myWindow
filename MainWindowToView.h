#pragma once
#include "Window.h"
class MainWindowToView : public Window
{
private:
	


public:
	MainWindowToView();

	//button action
	virtual void enterInputClick(wxCommandEvent& event);

	//Menu actions

	virtual void evt_NewFileClicked(wxCommandEvent& event);
	virtual void evt_loadFileClicked(wxCommandEvent& event);
	virtual void evt_saveFileClicked(wxCommandEvent& event); 
	virtual void evt_exitProgramClicked(wxCommandEvent& event); 
	virtual void evt_aoutClicked(wxCommandEvent& event); 

	~MainWindowToView();

};