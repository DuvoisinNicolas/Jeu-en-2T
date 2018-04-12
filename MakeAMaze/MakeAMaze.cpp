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

    CRoomLine aLine;

    for (CLittleUInt y (0); y < Room::myWallSize; ++y)
    {
        Room::myRoom.push_back(aLine);
        for (CLittleUInt x (0); x < Room::myWallSize; ++x)
        {
            Room::myRoom[y].push_back((isAnEdge (x, y, Room::myWallSize)) ? KWall : KEmptySpace);
        }
    }
}//Room

bool gameTools::isAnEdge (const CLittleUInt & x, const CLittleUInt & y, const CLittleUInt & maxSize)
{
    return ((y == 0) || (x == 0) || (y == maxSize - 1) || (x == maxSize - 1));
}//isAnEdge

void Room::display() const
{
    for (CRoomLine line : Room::myRoom)
    {
        for (char cell : line)
        {
            cout << setw(2) << cell;
        }
        cout << endl;
    }
}//Room::display


Stage::Stage (CLittleUInt stageSize)
{
    Stage::myStageSize = stageSize;

    CStageLine aLine;

    for (CLittleUInt y (0); y < stageSize; ++y)
    {
        myStage.push_back(aLine);
        for (CLittleUInt x (0); x < stageSize; ++x)
        {
            Room aRoom;
            aLine.push_back(aRoom);
        }
    }
}

void Stage::display() const
{
    for (CStageLine aLine : Stage::myStage)
    {
        for (Room aRoom : aLine)
        {
            aRoom.display();
        }
    }
}

CStageMap Stage::getStage() const
{
    return myStage;
}

