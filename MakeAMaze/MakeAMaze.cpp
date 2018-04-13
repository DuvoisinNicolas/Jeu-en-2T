#include <iostream>
#include <vector>
#include <iomanip>
#include "MakeAMaze.h"

using namespace std;
using namespace gameTools;

Room::Room (const std::vector<bool> & doorPositions)
{

    CRoomLine aLine;
    CLittleUInt nbPos (0);

    for (CLittleUInt y (0); y < Room::myWallSize; ++y)
    {
        Room::myRoom.push_back(aLine);
        for (CLittleUInt x (0); x < Room::myWallSize; ++x)
        {
            if (isAnEdge (x, y, Room::myWallSize))
            {

                Room::myRoom[y].push_back((doorPositions[nbPos] && isTheMiddleOfAWall(x, y, myWallSize)) ? KEmptySpace : KWall);
                ++nbPos;
            }
            else
            {
                Room::myRoom[y].push_back(KEmptySpace);
            }
        }
    }
}//Room

bool gameTools::isAnEdge (const CLittleUInt & x, const CLittleUInt & y, const CLittleUInt & maxSize)
{
    return ((y == 0) || (x == 0) || (y == maxSize - 1) || (x == maxSize - 1));
}//isAnEdge


bool gameTools::isTheMiddleOfAWall(const CLittleUInt & x, const CLittleUInt & y, const CLittleUInt maxSize)
{
    if (maxSize%2 == 1)
    {
        return ((x /2) == (maxSize/2)) || ((y/2) == (maxSize/2));
    }
    return false;

}//isTheMiddleOfAWall



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
            Room aRoom ({true,true,false,false});
            aLine.push_back(aRoom);
        }
    }
}//Stage

void Stage::display() const
{
    for (CStageLine aLine : Stage::myStage)
    {
        for (Room aRoom : aLine)
        {
            aRoom.display();
        }
       // cout << endl;
    }
}//Stage::display

CStageMap Stage::getStage() const
{
    return myStage;
}//Stage::getStage


