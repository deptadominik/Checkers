#include "GameBoard.h"
#include "BasicPawn.h"
#include "QueenPawn.h"
#include <iostream>
#include <Windows.h>
using namespace std;

const char tab[] = "ABCDEFGH";

void GameBoard::initialize() {


	for (int x = 0; x < 8; x++)
	{
		vector<Field> v1;
		for (int y = 0; y < 8; y++) {
			v1.push_back(Field());
		}
		boardFields.push_back(v1);
	}

	for (int x = 5; x < 8; x++) {
		for (int y = 0; y < 8; y++) {
			if ((x + y) % 2) {
				boardFields[x][y].setPawn(new BasicPawn(x, y, -1));
				this->wNumber++;
			} // WHITE
		}
	}

	for (int x = 0; x < 3; x++) {
		for (int y = 0; y < 8; y++) {
			if ((x + y) % 2) {
				boardFields[x][y].setPawn(new BasicPawn(x, y, 1));
				this->bNumber++;
			} // BLACK
		}
	}

	playerTurn = -1; // WHITE

}
ostream& operator <<(ostream& output, GameBoard& o)
{
	string dashes = "+-----";      //characters for field top and bottom bounds
	string whiteFieldFill = "|&&&&&";      //fill for white fields
	string blackFieldFill = "|     ";       // fill for black fields
	string line = "";
	string filler;
	int i, j, color;
	char chipState;

	output << "   ";
	for (i = 0; i < 8; i++) {     //display board top index
		output << "  " << tab[i] << "   ";
	}

	output << endl;
	output << " ";

	for (i = 0; i < 8; i++) {   //repeat 8 times, once for each row of fields
		output << " ";
		if (i == 0) line = "";
		else line = " ";

		for (j = 0; j < 8; j++) {     //build line of cells for boundary  ( +---+ )
			line = line + dashes;
		}
		output << line << "+" << endl;

		color = (i + 1) % 2;          // Mod 2 - needed to distinguish rows starting with white or black fields
									// color = 1 ->row starts with white field, color = 0 -> start with black field
		output << " ";
		line = " ";
		for (j = 0; j < 8; j++) {           //build first line for row of field
			if ((j + color) % 2) {
				filler = whiteFieldFill;        // fill stars for white fields    ( |&&&&&|)
			}
			else {
				filler = blackFieldFill;        // fill spaces for black fields     ( |    |)
			}
			line = line + filler;
		}

		output << line << "|" << endl;

		output << i + 1;
		line = " ";
		for (j = 0; j < 8; j++) {          //build second line for row of field ( |  x  | )
			if ((j + color) % 2) {
				filler = whiteFieldFill;        // fill with stars for white fields    ( |&&&&&|)
			}
			else {
				filler = "|  ";                  // fill spaces for blackfields
				if (o.boardFields[i][j].hasPawn())
				{
					chipState = o.boardFields[i][j].getPawn()->print();
				}
				else
					chipState = ' '; // get color of checker
				filler += chipState;                // add color of checker to line
				filler += "  ";
			}
			line = line + filler;
		}

		output << line << "|" << endl;
		output << " ";
		line = " ";
		for (j = 0; j < 8; j++) {           //build third line for row of field
			if ((j + color) % 2) {
				filler = whiteFieldFill;        // fill with stars for white fields   ( |&&&&&| )
			}
			else {
				filler = blackFieldFill;        // fill with spaces for black fields   ( |     | )
			}
			line = line + filler;
		}
		output << line << "|" << endl;
	}

	output << " ";
	line = " ";
	for (j = 0; j < 8; j++) {     //build line of cells for boundary on bottom of board   ( +---+ )
		line = line + dashes;
	}
	output << line << "+";
	return output;
}

bool GameBoard::checkWinCondition() const {

	if (bNumber == 0)
	{
		cout << "White player won!" << endl;
		return true;
	}
	else if (wNumber == 0)
	{
		cout << "Black player won!" << endl;
		return true;
	}
	else return false;

}

int GameBoard::getBNumber() const
{
	return bNumber;
}

int GameBoard::getWNumber() const
{
	return wNumber;
}

int GameBoard::getPlayerTurn() const
{
	return playerTurn;
}
void GameBoard::tryMove(int old_number, char old_letter, int new_number, char new_letter)
{
	int oldX = int(old_number) - 1, oldY = 0;
	int newX = int(new_number) - 1, newY = 0;
	int j = 0;
	for (char i : tab) {
		if (i == old_letter)
			oldY = j;
		++j;
	}
	j = 0;
	for (char i : tab) {
		if (i == new_letter)
			newY = j;
		++j;
	}

	Move trymv = NONE;

	if ((dynamic_cast<BasicPawn*>(boardFields[oldX][oldY].getPawn()) || dynamic_cast<QueenPawn*>(boardFields[oldX][oldY].getPawn()) && !boardFields[newX][newY].hasPawn() && playerTurn == boardFields[oldX][oldY].getPawn()->getColor()))
	{
		trymv = boardFields[oldX][oldY].getPawn()->move(boardFields, newX, newY);
	}

	switch (trymv.getType())
	{
	case NONE:
		throw "move!";
		break;

	case NORMAL:
	{
		Pawn* pawn = boardFields[oldX][oldY].getPawn();
		pawn->setX(newX);
		pawn->setY(newY);

		if ((pawn->getColor() == 1 && newX == 7) || (pawn->getColor() == -1 && newX == 0))
		{
			int color = pawn->getColor();
			delete boardFields[newX][newY].getPawn();
			boardFields[newX][newY].setPawn(new QueenPawn(newX, newY, color));
		}
		else
			boardFields[newX][newY].setPawn(pawn);

		boardFields[oldX][oldY].setPawn(nullptr);
		if (playerTurn == 1)
			playerTurn = -1;
		else
			playerTurn = 1;
		break;
	}

	case KILL:
		Pawn* pawn = boardFields[oldX][oldY].getPawn();
		pawn->setX(newX);
		pawn->setY(newY);
		if ((pawn->getColor() == 1 && newX == 7) || (pawn->getColor() == -1 && newX == 0))
		{
			int color = pawn->getColor();
			delete boardFields[newX][newY].getPawn();
			boardFields[newX][newY].setPawn(new QueenPawn(newX, newY, color));
		}
		else
			boardFields[newX][newY].setPawn(pawn);

		boardFields[oldX][oldY].setPawn(nullptr);

		Pawn* otherPawn = trymv.getPawn();
		boardFields[otherPawn->getX()][otherPawn->getY()].setPawn(nullptr);
		delete otherPawn;
		if (pawn->getColor() == 1) this->wNumber--;
		else this->bNumber--;
		break;

	}
}
GameBoard::~GameBoard()
{
	for (int x = 0; x < 8; x++)
	{
		for (int y = 0; y < 8; y++)
		{
			if (boardFields[x][y].getPawn())
			{
				delete boardFields[x][y].getPawn();
			}
		}
	}
}