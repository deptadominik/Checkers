#pragma once

#include "Field.h"
#include <fstream>
#include <vector>

using namespace std;

/** Contains methods for creating and writing out
board, listing the current score of the game.
Stores information about the given pawn movement,
displays message about a win. */

class GameBoard
{
private:
    vector<vector<Field>> boardFields;
    int bNumber, wNumber, playerTurn;

public:
    /** Constructor */
    GameBoard() { bNumber = 0, wNumber = 0, playerTurn = -1; }

    /** Builds the board */
    void initialize();

    /** Prints the board */
    friend ostream& operator <<(ostream& output, GameBoard& o);

    /** Checks if the player won */
    bool checkWinCondition() const;

    /** Gets the number of White pawns */
    int getWNumber() const;

    /** Gets the number of Black pawns */
    int getBNumber() const;

    /** Gets the information about whose movement is currently being executed */
    int getPlayerTurn() const;

    /** Processes a given movement, checks what type of movement will be performed */
    void tryMove(int, char, int, char);

    /** Destructor */
    ~GameBoard();
};
