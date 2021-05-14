#include <iostream>
#include <stdexcept>
#include <Windows.h>
#include <regex>
#include <fstream>

#include "GameBoard.h"


using namespace std;

int main()
{

	GameBoard board;
	board.initialize();

	while (board.checkWinCondition() != true)
	{
		cout << "Score for white: " << 12 - board.getBNumber() << endl;
		cout << "Score for black: " << 12 - board.getWNumber() << endl << endl;
		cout << board;

		int oldX, newX;
		char oldY, newY;

		cout << endl;

		if (board.getPlayerTurn() == -1)
			cout << "\nTurn: white\n";
		else
			cout << "\nTurn: black\n";

		bool checkPawn, checkMove;
		regex coordinates("[1-8]{1}[A-H]{1}");

		do
		{
			try
			{
				checkPawn = true;	// checking Pawn coordinates input
				cout << "Pick your Pawn (number letter): " << endl;
				cin >> oldX;
				cin >> oldY;
				oldY = toupper(oldY);
				string tmp = to_string(oldX) + oldY;
				if (!regex_match(tmp, coordinates))
				{
					checkPawn = false;
					throw "coordinates!";
				}
			}
			catch (const char* e)
			{
				cout << "Wrong " << e << " Try again.\n";
			}
		} while (!checkPawn);
		do
		{
			try
			{
				checkPawn = true;	// checking Move coordinates input

				cout << "Pick your move (number letter): " << endl;
				cin >> newX;
				cin >> newY;
				newY = toupper(newY);
				string tmp = to_string(newX) + newY;
				if (!regex_match(tmp, coordinates))
				{
					checkPawn = false;
					throw "coordinates!";
				}
			}
			catch (const char* e)
			{
				cout << "Wrong " << e << " Try again.\n";
			}
		} while (!checkPawn);
		try
		{
			board.tryMove(oldX, oldY, newX, newY);
		}
		catch (const char* e)
		{
			cout << "Wrong " << e << " Try again.\n";
			Sleep(4000);
		}
		system("cls");
	}

	ofstream toFile("output.txt");
	if (board.getPlayerTurn() == -1)
		toFile << "White player won! Here's the board: \n\n";
	else
		toFile << "Black player won! Here's the board: \n\n";
	toFile << board;
	toFile.close();

	return 0;
}