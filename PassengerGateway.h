
#ifndef PASSENGERGATEWAY_H
#define PASSENGERGATEWAY_H
#include <string>
#include <vector>
#include "Passenger.h"
#include "MobileApp.h"

using namespace std;

class PassengerGateway {
public:
    MobileApp app;

    explicit PassengerGateway(MobileApp app) { this->app = app; }

    bool login(Passenger passenger);

    void choosePaymentMethod(Passenger passenger);

    void showOrderHistory(Passenger passenger);

    void orderTaxiRide(Passenger passenger, string from, string to, string time);

    string getOrderTime(string from, string to);
};


#endif //HOMEWORK4_DANIIL_OKRUG_PASSENGERGATEWAY_H
