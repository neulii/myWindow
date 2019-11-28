#pragma once

#include "wx/wx.h"
#include "MainWindow.h"


class cApp : public wxApp
{
private:
	MainWindow *m_MainWindow = nullptr;

public:
	cApp();
	~cApp();

	virtual bool OnInit();
};


