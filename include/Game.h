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
	Game(std::vector<Player*> players, int winningPoints, int playedRounds, Player* cardMixerPlayer);

	void addPointsFromRound(int playerOnePoints, int playerTwoPoints);
	int getWinningPoints();
	std::vector<Player*> &getPlayers();

	int getDiffPointsLastRound();
	int getDiffPoints();

	int getPlayedRounds();
	void nextRound();

	const Player* getCardMixerPlayer();
	int findPlayer(const std::vector<Player*> playerList, const Player* player);

	Player* checkIfWon();

	void setCardMixerPlayer(int index);


	std::string getSerializeString();

};