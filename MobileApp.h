
#ifndef MOBILEAPP_H
#define MOBILEAPP_H
#include <string>
#include <vector>
#include <cstdio>

#include "Passenger.h"
#include "Driver.h"

using namespace std;

class MobileApp {
public:
    vector<vector<string>> activeOrders;
    vector<vector<string>> orders;

    MobileApp();

    explicit MobileApp(string name);

    bool authentication(Passenger passenger);

    bool authentication(Driver driver);

    vector<string> getOrderHistory(Passenger passenger);

    vector<string> getOrderHistory(Driver driver);

    void setStatus(Driver driver, bool status);

    bool getDriverStatus(Driver driver);

    void addOrder(Passenger passenger, string from, string to, string time);

    vector<vector<string>> getOrders();

    bool checkDriverAuth(Driver driver);

private:
    string name;

    vector<vector<string>> passengersInSystem;
    vector<vector<string>> driversInSystem;
};

#endif //HOMEWORK4_DANIIL_OKRUG_MOBILEAPP_H