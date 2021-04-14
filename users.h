#ifndef PSS_USERS_H
#define PSS_USERS_H

#include <string>
#include <vector>
#include "accessLevel.h"
#include "room.h"

using namespace std;

class Admin;

class User {
private:
    string name;
    AccessLevel accessLevel;
    vector<Room> customAccesses;
public:
    User(string name1, AccessLevel accessLevel1): name(std::move(name1)), accessLevel(accessLevel1) {}
    string getName();
    AccessLevel getAccessLevel();
    void addCustomAccess(Admin admin, Room toRoom);
    void cancelCustomAccess(Admin admin, Room toRoom);
    bool access(Room room);
};

class Student: public User {
private:
    int course;
public:
    Student(string name, int course1) : course(course1), User(std::move(name), GREEN) {}
    int getCourse() const;
};

class Guest: public User {
public:
    explicit Guest(string name) : User(std::move(name), BLUE) {}
};

class Professor : public User {
private:
    Cabinet cabinet;
    string joke;
public:
    Professor(string name, int cabinetRoom, string jokePhrase): cabinet(cabinetRoom), User(std::move(name), YELLOW), joke(jokePhrase) {}
    string getJoke();
    Cabinet getCabinet();
};

class LabEmployee : public User {
private:
    Cabinet lab;
public:
    LabEmployee(string name, Cabinet labRoom) : lab(labRoom), User(std::move(name), YELLOW) {}
    Cabinet getLab();
};

class Director : public User {
private:
    DirectorCabinet cabinet;
public:
    Director(string name, int cabinetRoom) : cabinet(cabinetRoom), User(std::move(name), RED) {}
    DirectorCabinet getCabinet();
};

class Admin : public User {
public:
    explicit Admin(string name) : User(std::move(name), RED) {}
};

#endif //PSS_USERS_H
