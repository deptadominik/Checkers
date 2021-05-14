#include "BasicPawn.h"
#include <iostream>

using namespace std;

char BasicPawn::print()
{
    if (this->getColor() == -1) // white
        return 'w';
    else
        return 'b';
}
Move BasicPawn::move(vector<vector<Field>> boardFields, int newX, int newY)
{

    if ((newX + newY) % 2 == 0)
    {
        return { NONE };
    }

    int x0 = this->getX();
    int y0 = this->getY();

    if (newX - x0 == (int)(this->getColor()) && abs(newY - y0) == 1)  // checks if the Move is normal
    {
        return { NORMAL };
    }
    else if (newX - x0 == (int)(this->getColor()) * 2 && abs(newY - y0) == 2) {
        int x1 = x0 + (newX - x0) / 2;
        int y1 = y0 + (newY - y0) / 2;
        if (boardFields[x1][y1].hasPawn() && boardFields[x1][y1].getPawn()->getColor() != this->getColor())
        {
            return { KILL, boardFields[x1][y1].getPawn() };
        }
    }

    return { NONE };
}
char BasicPawn::getType()
{
    return 'n';
}