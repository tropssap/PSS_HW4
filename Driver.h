

#ifndef DRIVER_H
#define DRIVER_H

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


#endif
