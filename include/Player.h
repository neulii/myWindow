#pragma once
#include <string>
#include <vector>

class Player
{
private:
	int playerPoints;
	std::string playerName;
	std::vector<int> pointList;

public:
	Player(std::string player);
	void addPoints(int points);
	bool subtractPoints(int points);

	int getPoints();
	std::string getPlayerName();

	std::vector<int>& getPlayerPointList();

	/* the data from one player is stored in one line:

		playername; totalpoints; points,points,points;

		e.g. neulii;200; 50,50,50,50,50,50,50,50;
	*/
	std::string getSerializeString();
};