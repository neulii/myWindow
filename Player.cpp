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