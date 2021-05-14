#pragma once
#include <vector>
#include "Move.h"

using namespace std;

/** A derived class, which inherits from the Pawn class. This class
has been modified to include the ability to move any number of fields diagonally. */

class QueenPawn : public Pawn
{
	/** Checks if the QueenPawn has the ability to move and also returns the possible pawn to be killed */
	Pawn* checkDiagonal(vector<vector<Field>> vector, int x0, int y0, int x, int y);
	bool isItRight = true;
public:
	using Pawn::Pawn;
	/** destructor */
	~QueenPawn();

	/** Checks which type of movement will be executed */
	Move move(vector<vector<Field>> array, int newX, int newY) override;

	/** Prints out the color of specific pawn*/
	char print() override;

	/** Gets the type of pawn (in this case - 'n') */
	char getType() override;
};

