#pragma once
#include "Window.h"
#include "Game.h"
class MainWindowToView : public Window
{
private:
	
	Game *game;

	std::string playerOneName = "stefan";
	std::string playerTwoName = "birgit";


public:
	MainWindowToView();

	//button action
	virtual void enterInputClick(wxCommandEvent& event);

	//Menu actions

	virtual void evt_NewGameClicked(wxCommandEvent& event);
	virtual void evt_loadFileClicked(wxCommandEvent& event);
	virtual void evt_saveFileClicked(wxCommandEvent& event); 
	virtual void evt_exitProgramClicked(wxCommandEvent& event); 
	virtual void evt_aoutClicked(wxCommandEvent& event); 

	~MainWindowToView();

};