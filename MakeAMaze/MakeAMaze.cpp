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
}//Room
Room::display() const
{
    C2DMap RoomToBuild;

    for (CLittleUInt y (0); y < Room::myWallSize; ++y)
    {
        for (CLittleUInt x (0); x < Room::myWallSize; ++x)
        {
            RoomToBuild[y][x] = (isAnEdge (x, y, Room::myWallSize)) ? wall : emptySpace;
        }
    }
}//display

