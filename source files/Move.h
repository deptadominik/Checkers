#pragma once
#include "Field.h"

enum MoveType { NONE, NORMAL, KILL };

class Pawn;

/** Stores information about a particular type of move */

class Move {
private:
    MoveType type;
    Pawn* pawn;
public:
    /** Gets the type of move */
    MoveType getType() const
    {
        return type;
    }

    /** Gets the specific pawn */
    Pawn* getPawn() const;

    /** Constructor */
    Move(MoveType type);

    /** 2nd constructor */
    Move(MoveType type, Pawn* pawn);
};
