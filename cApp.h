#pragma once

#include "wx/wx.h"
#include "MainWindow.h"
#include "Window.h"
#include "MainWindowToView.h"

class cApp : public wxApp
{
private:
	MainWindowToView* m_MainWindow = nullptr;

public:
	cApp();
	~cApp();

	virtual bool OnInit();
};