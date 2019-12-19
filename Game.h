#pragma once

#include "Player.h"

class Game
{
private:

	Player *playerOne;
	Player *playerTwo;

	std::vector<Player*> players;

	int playedRounds = 0;

	int winningPoints;

	bool gameIsOver = false;

public:

	Game(std::string playerNameOne, std::string playerNameTwo, int winningPoints);
	void addPointsFromRound(int playerOnePoints, int playerTwoPoints);
	int getWinningPoints();
	std::vector<Player*> &getPlayers();

	Player* checkIfWon();

};

