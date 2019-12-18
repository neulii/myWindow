#include "Game.h"
#include <iostream>

Game::Game(std::string playerNameOne, std::string playerNameTwo, int winningPoints) : winningPoints(winningPoints)
{
	playerOne = new Player(playerNameOne);
	playerTwo = new Player(playerNameTwo);

}

void Game::addPointsFromRound(int playerOnePoints, int playerTwoPoints)
{
	playerOne->addPoints(playerOnePoints);
	playerTwo->addPoints(playerTwoPoints);

	if (!(checkIfWon() == nullptr))
	{
		gameIsOver = true;
		std::cout << "winner is: " << checkIfWon()->getPlayerName();
	}
}

Player* Game::checkIfWon()
{
	Player* winnerIs = nullptr;

	if (playerOne->getPoints() >= winningPoints)
	{
		winnerIs = playerOne;
	}
	else if(playerTwo->getPoints() >= winningPoints)
	{
		winnerIs = playerTwo;
	}

	return winnerIs;
}