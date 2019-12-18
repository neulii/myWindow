#pragma once

#include "Player.h"

class Game
{
private:

	Player *playerOne;
	Player *playerTwo;

	int playedRounds = 0;

	int winningPoints;

	bool gameIsOver = false;

public:

	Game(std::string playerNameOne, std::string playerNameTwo, int winningPoints);
	void addPointsFromRound(int playerOnePoints, int playerTwoPoints);
	
	Player* checkIfWon();

};

