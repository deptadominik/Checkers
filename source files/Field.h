#pragma once
#include "Pawn.h"

class Pawn;

/** Gets information about the pawn, places the pawn on the field and checks if the current field is taken. */

class Field {
private:
    Pawn* pawn = nullptr;
public:
    Field();

    /** Sets the given pawn */
    void setPawn(Pawn* pawn);

    /** Gets the pawn */
    Pawn* const getPawn() const;

    /** Checks if there is a pawn on the field */
    bool hasPawn();

};