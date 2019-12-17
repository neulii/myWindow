#pragma once

#include "wx/wx.h"
#include "MainWindow.h"
#include "Window.h"

class cApp : public wxApp
{
private:
	MainWindow *m_MainWindow = nullptr;
	Window* m_Window = nullptr;

public:
	cApp();
	~cApp();

	virtual bool OnInit();
};