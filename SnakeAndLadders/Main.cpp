#include <iostream> //These are the includes for the program, they are used to call the class files, allowing for OOP
#include <vector>
#include <Windows.h>
#include <fstream>
#include "Dice.h"
#include "Ladders.h"
#include "Player.h"
#include "Snakes.h"
//#include "console.h" Code libary that looks to have broke in new version. Responsable for timing and clearing the screen

using namespace std;
static HANDLE hConsole;
static HWND console;


int main() {
	

	Player P1; //Creating the class variables
	Player P2;
	Dice Die;
	Snakes SK;
	Ladders LD;
	
	bool Win = false; //This variable will be used to loop the program until a player wins
	bool RollOff = false; //This variable is used to loop the roll off subprogram till there is a winner
	int Val = 0; //This will hold the value of the roll off value for one player, allowing for a comparison
	int TempVal = 0; //This will hold the value of the roll off value for the other player, allowing for a comparison
	int TurnCnt = 0; //This counts the number of turns taken
	string Winner; //Holds the name of the winner
	
	cout << "The Rules:" << endl; //These outputs just output the rules + objective of the game
	cout << "Players will take it in turns to roll a dice, moving forward that many spaces on the board" << endl;
	cout << "If a player lands on a ladder, they will climb up the board to the end of the ladder" << endl;
	cout << "If a player lands on a snake, they will slide down the board to the tail of the snake" << endl;
	cout << "The goal of the game is to reach the end of the board, The 25th place, before the other player. An exact roll is required to allow for the player to land on the 25th spot, otherwise they will remain stationary" << endl;
	cout << endl;
	cout << "The Board" << endl;
	cout << "21, 22, 23, 24, 25" << endl << "16, 17, 18, 19, 20" << endl << "11, 12, 13, 14, 15" << endl << "6 , 7 , 8 , 9 , 10" << endl << "1 , 2 , 3 , 4 , 5 " << endl << endl;
	cout << "Ladder Positions: " << endl << "4 -> 17" << endl << "7 -> 18" << endl << "15 -> 22" << endl << endl;
	cout << "Snake Positions: " << endl << "13 -> 2" << endl << "19 -> 6" << endl << "24 -> 3" << endl << endl;

	cout << "Please Enter Player 1's Name" << endl; //Allows for the players to enter their name
	P1.InpNa();
	cout << "Please Enter Player 2's Name" << endl;
	P2.InpNa();
	Die.StartDie(); //Initial class call - Used to create the seed for the dice to create a true random, see dice class
	//Console::clear();

	while (RollOff != true) //This is the subprogram that allows for the roll off to see who goes first, repeats until there is a winner before the program will continue 
	{
		Sleep(1000);
		cout << P1.Name << " rolled a:" << endl;
		Val = Die.Roll(); //calls the dice roll function
		Sleep(1000);
		cout << P2.Name << " rolled a:" << endl;
		TempVal = Die.Roll();


		if (Val > TempVal) {
			cout << P1.Name << " Wins The Roll Off" << endl;
			RollOff = true;
		}
		else if (TempVal > Val) {
			cout << P2.Name << " Wins The Roll Off" << endl;
			RollOff = true;
			//Manually run the 1st round, then play on from there altenating p1, then p2
			Val = Die.Roll();
			P2.Move(Val);
			P2.Pos = LD.LadChk(P2.Pos); //Only need to do the Ladder check as there are no snakes within the first 6 spaces
			cout << P2.Name << " Moved To Space " << P2.Pos << endl;
			//No need to do a win check, as the player can't win in the first turn
		};
	};
	

	while (Win != true) { //the while loop to repeat each player's turn untill someone wins
		TurnCnt++;//increments the turn counter
		if (Win != true) { //Checks that no-one has won before it takes it's next turn
			//Player 1's Go
			Sleep(1000);
			Val = Die.Roll();
			P1.Move(Val);
			P1.Pos = LD.LadChk(P1.Pos);//Checks if the player is on a ladder
			P1.Pos = SK.SnkChk(P1.Pos);//Checks if the player is on a snake
			if (P1.Pos > 25) { //checks if the player would be placed on a space greater than 25, if so reverts the move action - ensures that the player needs an exact roll
				P1.Pos = P1.HoldPos;
			};

			cout << P1.Name << " Moved To Space " << P1.Pos << endl;

			P1.HoldPos = P1.Pos;
			
		};

		if (P1.Pos == 25) {//checks if player 1 is the winner
			
			cout << P1.Name << " Wins";
			Win = true;
			Winner = P1.Name;
		};

		if (Win != true) {
			//Player 2's Go
			Sleep(1000);
			Val = Die.Roll();
			P2.Move(Val);
			P2.Pos = LD.LadChk(P2.Pos);//Checks if the player is on a ladder
			P2.Pos = SK.SnkChk(P2.Pos);//Checks if the player is on a snake


			if (P2.Pos > 25) {//checks if the player would be placed on a space greater than 25, if so reverts the move action - ensures that the player needs an exact roll
				P2.Pos = P2.HoldPos;
			};

			cout << P2.Name << " Moved To Space " << P2.Pos << endl;

			P2.HoldPos = P2.Pos;
			
		};

		if (P2.Pos == 25) {//checks if player 2 is the winner
			
			cout << P2.Name << " Wins";
			Winner = P2.Name;
			Win = true;
		};
	};
	
	ofstream Results;//Outputs to a txt file
	Results.open("Results.txt");
	Results << "The Winner is " << Winner << ". Won in " << TurnCnt << " turns \n" << endl;
	Results.close();


	
};