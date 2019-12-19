#include "Game.h"
#include <iostream>

Game::Game(std::string playerNameOne, std::string playerNameTwo, int winningPoints) : winningPoints(winningPoints)
{
	playerOne = new Player(playerNameOne);
	playerTwo = new Player(playerNameTwo);

	players.push_back(playerOne);
	players.push_back(playerTwo);


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

//TODO check winning points is not correct
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

int Game::getWinningPoints()
{
	return winningPoints;
}

std::vector<Player*> &Game::getPlayers()
{
	return players;
}

