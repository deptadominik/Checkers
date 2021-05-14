#pragma once
#include "Field.h"
#include "Move.h"
#include <vector>

class Field;
class Move;
using namespace std;

/** Base class that holds all the information about the pawn and its type (white or black), it's also the base class for the pawn type. */

class Pawn
{
private:
    int x, y, color;

public:
    /** Constructor*/
    Pawn(int x, int y, int color);

    /** Virtual destructor */
    virtual ~Pawn() {};

    /** Sets the color for a given Pawn */
    void setColor(int color);

    /** Gets the color of a given Pawn */
    int getColor() const;

    /** virtual method */
    virtual char print() = 0;

    /** virtual method */
    virtual Move move(vector<vector<Field>>, int, int) = 0;

    /** Gets the X coordinate */
    int getX() const;

    /** Gets the Y coordinate */
    int getY() const;

    /** Sets the X coordinate */
    void setX(int x);

    /** Sets the X coordinate */
    void setY(int y);

    /** virtual method */
    virtual char getType() = 0;
};