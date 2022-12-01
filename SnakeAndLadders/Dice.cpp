#include <iostream>
#include <cstdlib>
#include <ctime>
#include "Dice.h"
using namespace std;

void Dice::StartDie() {
	srand(static_cast<unsigned int>(time(0)));//initial random - uses time as a seed to avoid the same result each time
};

int Dice::Roll()
{
	
	Value = rand() % (6) + 1; //creates a random number to simulate a dice roll
	

	switch (Value) {//switch to check dice roll value, and outputs the correct ASCII Art dice
	case 1:
		cout << "-----------" << endl;
		cout << "|         |" << endl;
		cout << "|    O    |" << endl;
		cout << "|         |" << endl;
		cout << "-----------" << endl;
		break;
	case 2:
		cout << "-----------" << endl;
		cout << "|      O  |" << endl;
		cout << "|         |" << endl;
		cout << "|  O      |" << endl;
		cout << "-----------" << endl;
		break;
	case 3:
		cout << "-----------" << endl;
		cout << "|       O |" << endl;
		cout << "|    O    |" << endl;
		cout << "| O       |" << endl;
		cout << "-----------" << endl;
		break;
	case 4:
		cout << "-----------" << endl;
		cout << "| O     O |" << endl;
		cout << "|         |" << endl;
		cout << "| O     O |" << endl;
		cout << "-----------" << endl;
		break;
	case 5:
		cout << "-----------" << endl;
		cout << "| O     O |" << endl;
		cout << "|    O    |" << endl;
		cout << "| O     O |" << endl;
		cout << "-----------" << endl;
		break;
	case 6:
		cout << "-----------" << endl;
		cout << "| O     O |" << endl;
		cout << "| O     O |" << endl;
		cout << "| O     O |" << endl;
		cout << "-----------" << endl;
		break;
	};
	return Value;
	
};