#include "Player.h"
#include <iostream>

Player::Player(std::string name) : playerName(name), playerPoints(0)
{

}

Player::Player(std::string player, std::vector<int> pointList) : playerName(player), pointList(pointList)
{
	playerPoints = 0;

	for (int i = 0; i < pointList.size(); i++)
	{
		playerPoints += pointList.at(i);
	}

}

void Player::addPoints(int points)
{
	
	playerPoints += points;
	pointList.push_back(points);
}

bool Player::subtractPoints(int points)
{
	bool subtractionSuccessful = false;

	if (points <= playerPoints)
	{
		subtractionSuccessful = true;
		playerPoints -= points;
	}
	
	return subtractionSuccessful;
}

std::vector<int>& Player::getPlayerPointList()
{
	return pointList;
}

int Player::getPoints()
{
	return playerPoints;
}

std::string Player::getPlayerName() {
	return playerName;
}


/* the data from one player is stored in one line:

		playername; totalpoints; points,points,points;

		neulii;200; 50,50,50,50,50,50,50,50;

*/
std::string Player::getSerializeString()
{
	std::string toWrite;

	toWrite.append(playerName);
	toWrite.append(";");
	toWrite.append(std::to_string(playerPoints));
	toWrite.append(";");

	for (int i = 0; i < pointList.size(); i++)
	{
		toWrite.append(std::to_string(pointList.at(i)));
		toWrite.append(",");
	}

	toWrite.pop_back();
	toWrite.append("\n");

	return toWrite;
}

void Player::setPlayerName(std::string name)
{
	playerName = name;
}

void Player::setPlayerPointList(std::vector<int> values)
{
	pointList = values;
}