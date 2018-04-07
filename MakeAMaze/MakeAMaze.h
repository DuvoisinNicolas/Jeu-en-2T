#ifndef MAKEAMAZE_H_INCLUDED
#define MAKEAMAZE_H_INCLUDED

#include <vector>

typedef unsigned short CLittleUInt;
typedef std::vector<std::vector<char>> C2DMap;

namespace gameTools
{
    const CLittleUInt KminNbDoor = 2;
    const CLittleUInt KminNbWall = 4;
    const char wall = '#';
    const char emptySpace = ' ';

    bool isAnEdge (CLittleUInt x, CLittleUInt y, CLittleUInt maxSize);


    class Room
    {
        CLittleUInt myNbWall;
        CLittleUInt myWallSize;
        CLittleUInt myNbDoors;

        public :

        Room (CLittleUInt wallSize, CLittleUInt nbDoors = KminNbDoor, CLittleUInt nbWalls = KminNbWall);
        void display () const;


    };//Room
}//gameTools

#endif // MAKEAMAZE_H_INCLUDED
