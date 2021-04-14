
#ifndef PSS_ROOM_H
#define PSS_ROOM_H


#include "accessLevel.h"

class Room {
private:
    int number;
    AccessLevel accessLevel;
public:
    explicit Room(int number1, AccessLevel accessLevel1) : number(number1), accessLevel(accessLevel1) {}
    int getNumber() const;
    AccessLevel getAccessLevel();
    bool equals(Room room);
};

class ClassRoom : public Room {
public:
    explicit ClassRoom(int number) : Room(number, GREEN) {}
};

class LectureRoom : public Room {
private:
    int floor;
public:
    explicit LectureRoom(int number, int floor) : Room(number, (floor==1)?BLUE:GREEN) {}
    int getFloor() const;
};

class ConferenceRoom : public Room {
private:
    int floor;
public:
    explicit ConferenceRoom(int number, int floor) : Room(number, (floor==1)?BLUE:YELLOW) {}

    int getFloor() const;
};

class Cabinet : public Room {
public:
    explicit Cabinet(int number) : Room(number, YELLOW) {}

};

class DirectorCabinet : public Room {

public:
    explicit DirectorCabinet(int number) : Room(number, RED) {}

};


#endif //PSS_ROOM_H
