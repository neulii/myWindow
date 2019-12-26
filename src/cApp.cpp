#include "cApp.h"

//implenents main function -> entry point of program
// wxIMPLEMENT_APP(cAPP) -> change properties to subsystem windows
wxIMPLEMENT_APP_CONSOLE(cApp);

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
	m_MainWindow = new MainWindowToView();
	m_MainWindow->Show();

	return true;
}