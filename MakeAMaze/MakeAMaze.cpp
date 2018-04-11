#include <iostream>
#include <vector>
#include <iomanip>
#include "MakeAMaze.h"

using namespace std;
using namespace gameTools;

Room::Room (CLittleUInt wallSize, CLittleUInt nbDoors /*= KminNbDoor*/)
{
    Room::myWallSize = wallSize;
    Room::myNbDoors = nbDoors;

    CMapLine aLine;

    for (CLittleUInt y (0); y < Room::myWallSize; ++y)
    {
        Room::myRoom.push_back(aLine);
        for (CLittleUInt x (0); x < Room::myWallSize; ++x)
        {
            Room::myRoom[y].push_back((isAnEdge (x, y, Room::myWallSize)) ? KWall : KEmptySpace);
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
            cout << setw(2) << cell;
        }
        cout << endl;
    }
}//display

