//
// Created by Angel on 09.04.2021.
//

#ifndef HOMEWORK4_DANIIL_OKRUG_PASSENGER_H
#define HOMEWORK4_DANIIL_OKRUG_PASSENGER_H
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

#endif //HOMEWORK4_DANIIL_OKRUG_PASSENGER_H