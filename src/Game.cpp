#include "Game.h"
#include <iostream>

Game::Game(std::string playerNameOne, std::string playerNameTwo, int winningPoints) : winningPoints(winningPoints)
{
	playerOne = new Player(playerNameOne);
	playerTwo = new Player(playerNameTwo);

	players.push_back(playerOne);
	players.push_back(playerTwo);

	cardMixerPlayer = players.at(0);

}

Game::Game() :Game("noname", "noname", 1000) {

}

void Game::addPointsFromRound(int playerOnePoints, int playerTwoPoints)
{
	playerOne->addPoints(playerOnePoints);
	playerTwo->addPoints(playerTwoPoints);

	//absolutwert von differenz
	diffPointsLastRound = abs(playerTwoPoints - playerOnePoints);

	if (!(checkIfWon() == nullptr))
	{
		gameIsOver = true;
		std::cout << "winner is: " << checkIfWon()->getPlayerName();
	}
}

Player* Game::checkIfWon()
{
	Player* winnerIs = nullptr;

	if (playerOne->getPoints() -playerTwo->getPoints() >= winningPoints)
	{
		winnerIs = playerOne;
	}
	else if(playerTwo->getPoints() - playerOne->getPoints() >= winningPoints)
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

int Game::getPlayedRounds()
{
	return playedRounds;
}

void Game::nextRound()
{
	playedRounds++;
	//change cardmixer player
	cardMixerPlayer = players.at(playedRounds % players.size());

	diffPoints = abs(playerOne->getPoints() - playerTwo->getPoints());

	//std::cout << cardMixerPlayer->getPlayerName() << std::endl;
}

const Player* Game::getCardMixerPlayer()
{
	return cardMixerPlayer;
}

int Game::getDiffPointsLastRound()
{
	return diffPointsLastRound;
}

int Game::getDiffPoints()
{
	return diffPoints;
}

std::string Game::getSerializeString()
{
	std::string toWrite;

	//write on beginning the number of players
	toWrite.append(std::to_string(players.size()) + "\n");

	for (int i = 0; i < players.size(); i++)
	{
		toWrite.append(players.at(i)->getSerializeString());
	}

	toWrite.append(std::to_string(playedRounds) + "\n");
	toWrite.append(cardMixerPlayer->getPlayerName());
	
	return toWrite;
}
