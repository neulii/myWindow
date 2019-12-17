#include "MainWindowToView.h"
#include <iostream>

MainWindowToView::MainWindowToView() :Window(nullptr){

}

MainWindowToView::~MainWindowToView() {

}

void MainWindowToView::m_EnterInputClick(wxCommandEvent& event)
{ 
	event.Skip(); 

	std::cout << "punkte eintragen" << std::endl;
}