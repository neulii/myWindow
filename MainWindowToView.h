#pragma once
#include "Window.h"
class MainWindowToView : public Window
{
public:
	MainWindowToView();
	virtual void enterInputClick(wxCommandEvent& event);

	~MainWindowToView();

};