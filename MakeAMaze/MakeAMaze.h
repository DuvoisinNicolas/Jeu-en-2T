#ifndef MAKEAMAZE_H_INCLUDED
#define MAKEAMAZE_H_INCLUDED

#include <vector>

typedef unsigned short CLittleUInt;
typedef std::vector<char> CRoomLine;     // a line
typedef std::vector<CRoomLine> CRoomMap;   // a matrix


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
        CRoomMap myRoom;

        public :

        Room (CLittleUInt wallSize = KWallSize, CLittleUInt nbDoors = KminNbDoor);  // constructor building a room
        void display () const;  // displays the room


    };//Room

    typedef std::vector<Room> CStageLine; //dunno how to do differently: need a fix
    typedef std::vector<CRoomLine> CStageMap; // same as above

    class Stage
    {
        CLittleUInt myStageSize;
        CStageMap myStage;

        public:

        Stage();
    };//Stage

}//gameTools

#endif // MAKEAMAZE_H_INCLUDED
