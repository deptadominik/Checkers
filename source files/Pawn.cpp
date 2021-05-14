#include "Pawn.h"

Pawn::Pawn(int x, int y, int color)
{
    this->x = x;
    this->y = y;
    setColor(color);
}
void Pawn::setColor(int color)
{
    Pawn::color = color;
}
int Pawn::getColor() const {
    return this->color;
}
int Pawn::getX() const
{
    return x;
}

int Pawn::getY() const
{
    return y;
}
void Pawn::setX(int x) {
    Pawn::x = x;
}

void Pawn::setY(int y) {
    Pawn::y = y;
}