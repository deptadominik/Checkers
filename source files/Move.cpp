#include "Move.h"

Move::Move(MoveType type, Pawn* pawn)
{
    this->type = type;
    this->pawn = pawn;
}

Move::Move(MoveType type)
{
    this->type = type;
}

Pawn* Move::getPawn() const
{
    return this->pawn;
}