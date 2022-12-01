#include <iostream>
#include "Ladders.h"
int Ladders::LadChk(int Pos)
{

	
	switch (Pos)//checks the player's position, changes it to the end of the ladder if it matches the start 
	{
	case 4:
		Pos = 17;
		std::cout << "Landed On A Ladder, Moving To Position" << Pos << std::endl;
		break;
	case 7:
		Pos = 18;
		std::cout << "Landed On A Ladder, Moving To Position" << Pos << std::endl;
		break;
	case 15:
		Pos = 22;
		std::cout << "Landed On A Ladder, Moving To Position" << Pos << std::endl;
		break;
	};

	

	return Pos;
};

