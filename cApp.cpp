#include "cApp.h"

//implenents main function -> entry point of program
wxIMPLEMENT_APP(cApp);

//constructor
cApp::cApp()
{

}


//deconstructor
cApp::~cApp()
{

}

bool cApp::OnInit()
{
	m_MainWindow = new MainWindow();
	m_MainWindow->Show();

	return true;
}