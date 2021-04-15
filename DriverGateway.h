

#ifndef DRIVERGATEWAY_H
#define DRIVERGATEWAY_H


#include "Driver.h"
#include "MobileApp.h"

class DriverGateway {
public:
    MobileApp app;

    vector<vector<string>> orders;

    explicit DriverGateway(MobileApp app) { this->app = app; }

    bool login(Driver driver);

    void showOrderHistory(Driver driver);

    void updateStatus(Driver drive, bool status);

    void showCarInfo(Driver driver);

    void getOrders();

    void showOrders(Driver driver);

    bool checkAuth(Driver driver);

    int getOrderNumber();

    void takeOrder(Driver driver, Passenger passenger, int orderId);
};

#endif