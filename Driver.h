//
// Created by Angel on 10.04.2021.
//

#ifndef HOMEWORK4_DANIIL_OKRUG_DRIVER_H
#define HOMEWORK4_DANIIL_OKRUG_DRIVER_H

#include <string>
#include <utility>
#include "Car.h"

using namespace std;

class Driver {
public:
    Car car;

    explicit Driver(string name, Car car) {
        this->name = move(name);
        this->car = move(car);
    }

    string getName() { return name; }

    bool getStatus() { return status; }

    void setStatus(bool status) { this->status = status; }
private:
    string name;
    bool status =  false;
};


#endif //HOMEWORK4_DANIIL_OKRUG_DRIVER_H
