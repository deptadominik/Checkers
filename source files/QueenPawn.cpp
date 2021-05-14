#include "QueenPawn.h"
#include "GameBoard.h"
#include <iostream>

using namespace std;

QueenPawn::~QueenPawn() {}

char QueenPawn::print() {
    if (this->getColor() == -1)
        return 'W';
    else
        return 'B';
}

Move QueenPawn::move(vector<vector<Field>> boardFields, int newX, int newY) {

    if ((newX + newY) % 2 == 0)
    {
        return { NONE };
    }

    int x0 = this->getX();
    int y0 = this->getY();
    bool isPawnOnWay = false;

    if (abs(newX - x0) == abs(newY - y0))
    {
        Pawn* pawn = checkDiagonal(boardFields, x0, y0, newX, newY);
        if (pawn != nullptr && pawn->getColor() != boardFields[x0][y0].getPawn()->getColor())
            isPawnOnWay = true;
        if (isPawnOnWay && this->isItRight == true)
        {
            return Move(KILL, pawn);
        }
        else if (!isPawnOnWay && this->isItRight == true)
            return { NORMAL };
        else if (!isPawnOnWay && this->isItRight == false)
            return { NONE };
    }
    else
        return { NONE };
}

Pawn* QueenPawn::checkDiagonal(vector<vector<Field>> boardFields, int oldX, int oldY, int newX, int newY)
{
    if (newX - oldX > 0 && newY - oldY > 0) {
        for (int i = newX - 1, j = newY - 1; i > oldX && j > oldY; i--, j--)
        {
            if (boardFields[i][j].hasPawn())
            {
                int _i = i, _j = j;
                for (int i1 = _i - 1, j1 = _j - 1; i1 > oldX && j1 > oldY; i1--, j1--)
                {
                    if (boardFields[i1][j1].hasPawn())
                    {
                        this->isItRight = false;
                        return nullptr;
                    }
                }
                this->isItRight = true;
                return boardFields[i][j].getPawn();
            }
        }
    }
    else if (newX - oldX < 0 && newY - oldY < 0) {
        for (int i = newX + 1, j = newY + 1; i < oldX && j < oldY; i++, j++)
        {
            if (boardFields[i][j].hasPawn())
            {
                int _i = i, _j = j;
                for (int i1 = _i + 1, j1 = _j + 1; i1 < oldX && j1 < oldY; i1++, j1++)
                {
                    if (boardFields[i1][j1].hasPawn())
                    {
                        this->isItRight = false;
                        return nullptr;
                    }
                }
                this->isItRight = true;
                return boardFields[i][j].getPawn();
            }
        }
    }
    else if (newX - oldX < 0 && newY - oldY > 0)
    {
        for (int i = newX + 1, j = newY - 1; i < oldX && j > oldY; i++, j--)
        {
            if (boardFields[i][j].hasPawn())
            {
                int _i = i, _j = j;
                for (int i1 = _i + 1, j1 = _j - 1; i1 < oldX && j1 > oldY; i1++, j1--)
                {
                    if (boardFields[i1][j1].hasPawn())
                    {
                        this->isItRight = false;
                        return nullptr;
                    }
                }
                this->isItRight = true;
                return boardFields[i][j].getPawn();
            }
        }
    }
    else if (newX - oldX > 0 && newY - oldY < 0)
    {
        for (int i = newX - 1, j = newY + 1; i > oldX && j < oldY; i--, j++)
        {
            if (boardFields[i][j].hasPawn())
            {
                int _i = i, _j = j;
                for (int i1 = _i - 1, j1 = _j + 1; i1 > oldX && j1 < oldY; i1--, j1++)
                {
                    if (boardFields[i1][j1].hasPawn())
                    {
                        this->isItRight = false;
                        return nullptr;
                    }
                }
                this->isItRight = true;
                return boardFields[i][j].getPawn();
            }
        }
    }
    return nullptr;
}

char QueenPawn::getType()
{
    return 'q';
}
