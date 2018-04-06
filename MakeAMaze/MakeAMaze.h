#ifndef MAKEAMAZE_H_INCLUDED
#define MAKEAMAZE_H_INCLUDED

typedef unsigned short CLittleUInt;

namespace gameTools
{
    const CLittleUInt KminNbDoor = 2;
    const CLittleUInt KminNbWall = 4;

    class Room
    {
        CLittleUInt nbWall;
        CLittleUInt wallSize;
        CLittleUInt nbDoors;

        public :

        Room (CLittleUInt doors = KminNbDoor, CLittleUInt walls = KminNbWall, CLittleUInt wallSize);


    };//Room
}//gameTools

#endif // MAKEAMAZE_H_INCLUDED
