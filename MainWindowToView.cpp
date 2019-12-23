#include "MainWindowToView.h"
#include <iostream>

MainWindowToView::MainWindowToView() :Window(nullptr){
	m_statusBar->SetStatusText( "erstes",0);
	m_statusBar->SetStatusText( "zweites",1);
	m_statusBar->SetStatusText( "drittes",2);

	int fieldWidth[] = { 100,50,100 };

	m_statusBar->SetStatusWidths(3, fieldWidth);
	
#ifdef DEBUG

	startNewGame();

#endif // DEBUG

}

MainWindowToView::~MainWindowToView() {

}

void MainWindowToView::enterInputClick(wxCommandEvent& event)
{ 
	std::string input_one;
	std::string input_two;
	int points_pTwo;
	int points_pOne;

	//check input if empty
	if (!(m_playerOneInput->GetValue().IsEmpty() || m_playerTwoInput->GetValue().IsEmpty()))
	{
		try
		{
			//get numbers from inputfield
			input_one = static_cast<std::string>(m_playerOneInput->GetValue());
			input_two = static_cast<std::string>(m_playerTwoInput->GetValue());

			//convert input to int
			
			points_pOne = std::stoi(input_one);
			points_pTwo = std::stoi(input_two);
			
			//std::cout << points_pOne << "    " << points_pTwo << std::endl;
		}
		catch (const std::exception& error)
		{
			std::cout << "fehler beim auslesen!  " << error.what() << std::endl;
			
			return;
			//std::cout << error.what() << std::endl;
		}

		//add values to players

		game->addPointsFromRound(points_pOne, points_pTwo);

		m_pointsPlayerOneDisplay->SetLabelText(std::to_string(game->getPlayers().at(0)->getPoints()));
		m_pointsPlayerTwoDisplay->SetLabelText(std::to_string(game->getPlayers().at(1)->getPoints()));
		
		m_playerOneInput->Clear();
		m_playerTwoInput->Clear();
		
		//insert row in the top 
		m_pointTable->InsertRows(game->getPlayedRounds(),1);
		
		m_pointTable->SetCellValue(game->getPlayedRounds(), 0, std::to_string(game->getPlayers().at(0)->getPlayerPointList().at(game->getPlayedRounds())));
		m_pointTable->SetCellValue(game->getPlayedRounds(), 1, std::to_string(game->getPlayers().at(1)->getPlayerPointList().at(game->getPlayedRounds())));
		m_pointTable->MakeCellVisible(game->getPlayedRounds(), 0);

		m_pointTable->SendSizeEventToParent();

		m_playerOneInput->SetFocus();
	
		game->nextRound();
	}
	//if input fields empty
	else
	{
		std::cout << "bitte beide felder ausfuellen!!!" << std::endl;
		if (m_playerOneInput->IsEmpty())
		{
			m_playerOneInput->SetFocus();
		}
		else
		{
			m_playerTwoInput->SetFocus();
		}
	}
	
	event.Skip(); 
}

void MainWindowToView::evt_NewGameClicked(wxCommandEvent& event)
{	
	std::cout << "new game menu clicked" << std::endl;
	startNewGame();
}

void MainWindowToView::startNewGame()
{
	//enable controls
	m_pointsPlayerOneDisplay->Enable();
	m_pointsPlayerTwoDisplay->Enable();
	m_playerOneNameText->Enable();
	m_playerTwoNameText->Enable();
	m_playerOneInput->Enable();
	m_playerTwoInput->Enable();
	m_EnterInput->Enable();
	m_pointTable->Enable();
	m_winningPoints->Enable();

	//create new game
	game = new Game(playerOneName, playerTwoName, 500);

	m_playerOneNameText->SetLabel(playerOneName);
	m_playerTwoNameText->SetLabel(playerTwoName);

	//set winning points to label
	m_winningPoints->SetLabel(std::to_string(game->getWinningPoints()));

	std::string test = game->getPlayers().at(0)->getPlayerName();

	m_pointTable->SetColLabelValue(0,game->getPlayers().at(0)->getPlayerName());
	m_pointTable->SetColLabelValue(1,game->getPlayers().at(1)->getPlayerName());
	m_playerOneInput->SetFocus();
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

void MainWindowToView::evt_aboutClicked(wxCommandEvent& event)
{
	std::cout << "about" << std::endl;
}

void MainWindowToView::evt_enterInInputfield(wxCommandEvent& event)
{
	std::string input_one;
	std::string input_two;

	int points_pTwo = 0;
	int points_pOne = 0;

	std::cout << event.GetId() << std::endl;
	//get input from field
	input_one = static_cast<std::string>(m_playerOneInput->GetValue());

	//check if infput is valid

	if(!CheckIfCorrectValue(input_one))
	{
		std::cout << "input one is not valid" << std::endl;
		m_playerOneInput->SetSelection(0, input_one.length());
		return;

	}
	
	//check input two if correct input


	
	input_two = static_cast<std::string>(m_playerTwoInput->GetValue());

	std::cout << input_one << "    " << input_two << std::endl;

	event.Skip(); 
}

bool MainWindowToView::CheckIfCorrectValue(std::string value)
{
	int digitsInString = 0;
	int stringLength = value.length();

	for(int i = 0; i<stringLength; i++)
	{
		if(!isdigit(value.at(i)))
		{
			return false;
		}
		else
		{
			digitsInString++;
		}		
	}

	if(digitsInString == value.length())
	{
		return true;
	}
	else 
		return false;
}