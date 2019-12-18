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

void MainWindowToView::evt_NewFileClicked(wxCommandEvent& event)
{
	std::cout << "new file" << std::endl;
}

void MainWindowToView::evt_loadFileClicked(wxCommandEvent& event)
{
	std::cout << "load file" << std::endl;
}

void MainWindowToView::evt_saveFileClicked(wxCommandEvent& event)
{
	std::cout << "save file" << std::endl;
}

void MainWindowToView::evt_exitProgramClicked(wxCommandEvent& event)
{
	std::cout << "exit" << std::endl;
}

void MainWindowToView::evt_aoutClicked(wxCommandEvent& event)
{
	std::cout << "about" << std::endl;
}
