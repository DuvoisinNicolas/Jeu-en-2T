#include <iostream>
#include <vector>
#include "MakeAMaze.h"

using namespace std;
using namespace gameTools;

Room::Room (CLittleUInt wallSize, CLittleUInt nbDoors /*= KminNbDoor*/, CLittleUInt nbWalls /*= KminNbWall*/)
{
    Room::myWallSize = wallSize;
    Room::myNbDoors = nbDoors;
    Room::myNbWall = nbWalls;

    for (CLittleUInt y (0); y < Room::myWallSize; ++y)
    {
        for (CLittleUInt x (0); x < Room::myWallSize; ++x)
        {
            Room::myRoom[y][x] = (isAnEdge (x, y, Room::myWallSize)) ? KWall : KEmptySpace;
        }
    }
}//Room

bool gameTools::isAnEdge (CLittleUInt x, CLittleUInt y, CLittleUInt maxSize)
{
    return ((y == 0) || (x == 0) || (y == maxSize - 1) || (x == maxSize - 1));
}//isAnEdge

void Room::display() const
{
    for (CMapLine line : Room::myRoom)
    {
        for (char cell : line)
        {
            cout << cell;
        }
        cout << endl;
    }
}//display

