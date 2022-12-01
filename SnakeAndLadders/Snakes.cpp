#include <iostream>
#include "Snakes.h"



int Snakes::SnkChk(int Pos)
{

	switch (Pos) // checks the player's position, changes it to the end of the snake if it matches the start 
	{
	case 13:
		Pos = 2;
		std::cout << "Landed On A Snake, Moving To Position" << Pos << std::endl;
		break;
	case 19:
		Pos = 6;
		std::cout << "Landed On A Snake, Moving To Position" << Pos << std::endl;
		break;
	case 24:
		Pos = 3;
		std::cout << "Landed On A Snake, Moving To Position" << Pos << std::endl;
		break;
	};
	
	

	return Pos;
};