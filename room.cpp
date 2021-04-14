#include "room.h"

int Room::getNumber() const {
    return number;
}

int LectureRoom::getFloor() const{
    return floor;
}
int ConferenceRoom::getFloor() const{
    return floor;
}

AccessLevel Room::getAccessLevel() {
    return accessLevel;
}

bool Room::equals(Room room) {
    return number == room.getNumber() && accessLevel == room.getAccessLevel();
}


