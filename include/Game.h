#pragma once

#include "Player.h"

class Game
{
private:

	Player *playerOne;
	Player *playerTwo;

	std::vector<Player*> players;

	int playedRounds = 0;
	int diffPointsLastRound = 0;
	int diffPoints = 0;

	Player* cardMixerPlayer = nullptr;

	int winningPoints;

	bool gameIsOver = false;

public:

	Game(std::string playerNameOne, std::string playerNameTwo, int winningPoints);
	Game();

	void addPointsFromRound(int playerOnePoints, int playerTwoPoints);
	int getWinningPoints();
	std::vector<Player*> &getPlayers();

	int getDiffPointsLastRound();
	int getDiffPoints();

	int getPlayedRounds();
	void nextRound();

	const Player* getCardMixerPlayer();

	Player* checkIfWon();

	std::string getSerializeString();

};