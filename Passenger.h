

#ifndef PASSENGER_H
#define PASSENGER_H
#include <string>
#include <utility>

using namespace std;

class Passenger {
public:
    explicit Passenger(string name) { this->name = move(name); }

    string getName() { return name; }
private:
    string name;
};

#endif