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

	std::vector<int>& getPlayerPointList();
	

};

