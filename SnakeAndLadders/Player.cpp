#include <iostream>
#include "Player.h"
#include "Snakes.h"
#include "Ladders.h"
#include "Dice.h"


void Player::InpNa()
{
	std::cin >> Name; //function to allow users to input their name
	
	
};

void Player::Move(int x)//Function to keep track of the player's position
{
	
	Pos = Pos + x;
};

