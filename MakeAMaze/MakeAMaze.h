#ifndef MAKEAMAZE_H_INCLUDED
#define MAKEAMAZE_H_INCLUDED

#include <vector>

typedef unsigned short CLittleUInt;
typedef std::vector<char> CMapLine;     // a line
typedef std::vector<CMapLine> C2DMap;   // a matrix

namespace gameTools          // Contains game tools
{
    const CLittleUInt KminNbDoor = 1;   // Min doors of a room
    const CLittleUInt KWallSize = 15;   // Size of a room

    const char KWall = '#' ;            // Wall cell
    const char KEmptySpace = ' ';       // Empty cell

    bool isAnEdge (CLittleUInt x, CLittleUInt y, CLittleUInt maxSize);  // function testing if there's a border on a cell

    class Room      // class containing a room
    {
        CLittleUInt myWallSize;
        CLittleUInt myNbDoors;
        C2DMap myRoom;

        public :

        Room (CLittleUInt wallSize = KWallSize, CLittleUInt nbDoors = KminNbDoor);  // constructor building a room
        void display () const;  // displays the room


    };//Room
}//gameTools

#endif // MAKEAMAZE_H_INCLUDED
