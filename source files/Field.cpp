#include "Field.h"

void Field::setPawn(Pawn* pawn)
{
    Field::pawn = pawn;
}

Field::Field()
{
    this->pawn = nullptr;
}
Pawn* const Field::getPawn() const {
    return pawn;
}

bool Field::hasPawn() {
    return this->pawn != nullptr;
}