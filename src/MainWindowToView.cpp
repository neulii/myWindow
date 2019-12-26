#include "MainWindowToView.h"
#include <iostream>
#include "main_lib.h"

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
	//m_EnterInput->Enable();
	m_pointTable->Enable();
	m_winningPoints->Enable();

	//create new game
	game = new Game(playerOneName, playerTwoName, 500);

	m_playerOneNameText->SetLabel(playerOneName);
	//m_playerOneNameText->SetBackgroundColour(*wxRED);
	m_pointsPlayerOneDisplay->SetBackgroundColour(*wxGREEN);
	m_playerTwoNameText->SetLabel(playerTwoName);

	//set winning points to label
	m_winningPoints->SetLabel(std::to_string(game->getWinningPoints()));

	std::string test = game->getPlayers().at(0)->getPlayerName();

	//tabellen beschriftung
	m_pointTable->SetColLabelValue(0,game->getPlayers().at(0)->getPlayerName());
	m_pointTable->SetColLabelValue(1,game->getPlayers().at(1)->getPlayerName());
	m_pointTable->SetColLabelValue(2, "Diff");
	m_pointTable->SetMinSize(wxSize(247, -1));

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

	if(event.GetId()==ID_PLAYER_ONE)
	{
		input_one = static_cast<std::string>(m_playerOneInput->GetValue());

		//if not valid return
		if(!neulib::checkIfStringIsValidNumber(input_one))
		{
			std::cout << "input one is not valid" << std::endl;
			m_playerOneInput->SetSelection(0, input_one.length());
			return;

		}
		else
		{
			//std::cout << "input valid" << std::endl;
			m_playerTwoInput->SetFocus();
		}
	}	

	//check input two if correct input

	if(event.GetId()==ID_PLAYER_TWO)
	{
		input_two = static_cast<std::string>(m_playerTwoInput->GetValue());
		input_one = static_cast<std::string>(m_playerOneInput->GetValue());

		if(!neulib::checkIfStringIsValidNumber(input_two))
		{
			std::cout << "input two is not valid" << std::endl;
			m_playerTwoInput->SetSelection(0, input_two.length());
			return;
		}
		else
		{
			//when input field 2 is ok check input field one for safety
			std::cout << input_one << std::endl;
			if(neulib::checkIfStringIsValidNumber(input_one))
			{
				std::cout << "add to points" << std::endl;

				//convert input to int
			
				points_pOne = std::stoi(input_one);
				points_pTwo = std::stoi(input_two);

				//add values to players
				game->addPointsFromRound(points_pOne, points_pTwo);

				wxColor tempColor = m_pointsPlayerTwoDisplay->GetBackgroundColour();
	m_pointsPlayerTwoDisplay->SetBackgroundColour(m_pointsPlayerOneDisplay->GetBackgroundColour());
	m_pointsPlayerOneDisplay->SetBackgroundColour(tempColor);

	std::cout << "change color" << std::endl;
				addPointsAndupdateGui();

			}
			else
			{
				std::cout << "input two is not valid" << std::endl;
				m_playerOneInput->SetFocus();
				m_playerOneInput->SetSelection(0, input_one.length());
				return;
			}
		}
	}

	event.Skip(); 
}

void MainWindowToView::evt_activateWindow(wxActivateEvent& event)
{
	if (event.GetActive())
	{
		
		m_playerOneInput->SetFocus();
	
		//m_playerOneInput->SetSelection(0, m_playerOneInput->GetValue().length());

	}

	event.Skip();
}

void MainWindowToView::addPointsAndupdateGui() {


	m_pointsPlayerOneDisplay->SetLabelText(std::to_string(game->getPlayers().at(0)->getPoints()));
	m_pointsPlayerTwoDisplay->SetLabelText(std::to_string(game->getPlayers().at(1)->getPoints()));
	
	int playerOnePoints = game->getPlayers().at(0)->getPlayerPointList().at(game->getPlayedRounds());
	int playerTwoPoints = game->getPlayers().at(1)->getPlayerPointList().at(game->getPlayedRounds());

	m_playerOneInput->Clear();
	m_playerTwoInput->Clear();

	//insert row in the top 
	m_pointTable->InsertRows(game->getPlayedRounds(), 1);

	//mark winner in table


	if (playerOnePoints > playerTwoPoints)
	{
		std::cout << game->getPlayers().at(0)->getPlayerName() << " wins!!" << std::endl;
		m_pointTable->SetCellBackgroundColour(game->getPlayedRounds(), 0, *wxGREEN);
	}
	if (playerTwoPoints > playerOnePoints)
	{
		std::cout << game->getPlayers().at(1)->getPlayerName() << " wins!!" << std::endl;
		m_pointTable->SetCellBackgroundColour(game->getPlayedRounds(), 1, *wxGREEN);
	}
	if (playerTwoPoints == playerOnePoints)
	{
		m_pointTable->SetCellBackgroundColour(game->getPlayedRounds(), 0, *wxYELLOW);
		m_pointTable->SetCellBackgroundColour(game->getPlayedRounds(), 1, *wxYELLOW);
	}

	
	m_pointTable->SetCellValue(game->getPlayedRounds(), 0, std::to_string(game->getPlayers().at(0)->getPlayerPointList().at(game->getPlayedRounds())));
	m_pointTable->SetCellValue(game->getPlayedRounds(), 1, std::to_string(game->getPlayers().at(1)->getPlayerPointList().at(game->getPlayedRounds())));
	
	m_pointTable->SetCellValue(game->getPlayedRounds(), 2, std::to_string(game->getDiffPointsLastRound()));
	m_pointTable->MakeCellVisible(game->getPlayedRounds(), 0);


	m_playerOneInput->SetFocus();

	
	m_pointTable->SendSizeEventToParent();


	game->nextRound();
}