#include "MainWindowToView.h"
#include <iostream>

MainWindowToView::MainWindowToView() :Window(nullptr){
	m_statusBar->SetStatusText( "erstes",0);
	m_statusBar->SetStatusText( "zweites",1);
	m_statusBar->SetStatusText( "drittes",2);

	int fieldWidth[] = { 100,50,100 };

	m_statusBar->SetStatusWidths(3, fieldWidth);

}

MainWindowToView::~MainWindowToView() {

}

void MainWindowToView::enterInputClick(wxCommandEvent& event)
{ 
	event.Skip(); 

	std::cout << "punkte eintragen" << std::endl;
}