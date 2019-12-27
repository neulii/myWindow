#include "Player.h"

Player::Player(std::string name) : playerName(name), playerPoints(0)
{

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