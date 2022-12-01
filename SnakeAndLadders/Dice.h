#ifndef Dice_H
#define Dice_H


#include <iostream>

class Dice {

public:
	int Value;//holds the value of the dice
	int Roll();//function to roll the dice - returns the value to allow for the position to be used
	void StartDie();//Initial randomise of dice values
};
#endif // !Dice_H