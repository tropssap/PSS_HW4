#include "users.h"
#include<iostream>
#include <string>
string User::getName() {
    return name;
}

AccessLevel User::getAccessLevel() {
    return accessLevel;
}
bool User::access(Room toRoom) {
    if (accessLevel >= toRoom.getAccessLevel()) return true;

    for (auto room : customAccesses) {
        if (toRoom.equals(room)) return true;
    }
    return false;
}

void User::addCustomAccess(Admin admin, Room toRoom) {
    for (auto room : customAccesses) {
        if (room.equals(toRoom)) {
                std::cout << admin.getName() << " has granted " << this->getName() << "'s access to "<<  toRoom.getNumber() <<" cabinet" << endl;
                return;
        }
    }

    std::cout << admin.getName() << " has granted " << this->getName() << "'s access to "<<  toRoom.getNumber() <<" cabinet" << endl;
    customAccesses.push_back(toRoom);
}


void User::cancelCustomAccess(Admin admin, Room toRoom) {
    for (int i = 0; i < customAccesses.size(); i++) {
        if (customAccesses[i].equals(toRoom)) {
            customAccesses.erase(customAccesses.begin() + i);
            std::cout << admin.getName() << " has canceled " << this->getName() << "'s access to "<< toRoom.getNumber() <<" cabinet" << endl;
            return;
        }
    }
}



int Student::getCourse() const {
    return course;
}

Cabinet Professor::getCabinet() {
    return cabinet;
}

string Professor::getJoke(){
    return joke;

}

Cabinet LabEmployee::getLab() {
    return lab;
}

DirectorCabinet Director::getCabinet() {
    return cabinet;
}


