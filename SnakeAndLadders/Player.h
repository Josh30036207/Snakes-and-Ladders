#ifndef Player_H
#define Player_H


#include <iostream>

class Player {
public:
	std::string Name; //This will hold the player's name
	int Pos = 0; //This will hold the Player's position
	int HoldPos = 0; //This variable will hold the player's position for the comparison to ensure that they land on a 25


	void InpNa();
	void Move(int DieVal);
	

};
#endif // !Player_H