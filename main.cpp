#include <iostream>
#include <ctime>

#include "PassengerGateway.h"
#include "Passenger.h"
#include "Car.h"
#include "DriverGateway.h"

using namespace std;

int getRandomNumber(int min, int max);

int main() {
    srand(time(0));
    MobileApp mobileApp;
    PassengerGateway passengerGateway(mobileApp);
    DriverGateway driverGateway(mobileApp);
    Passenger passenger_Daniil("Daniil");
    ComfortCar comfortCar("comfortCar1", "numberPlate", Car::BLACK, "25/25");
    Driver driver_Nurdaulet("Nurdaulet", comfortCar);

    passengerGateway.login(passenger_Daniil);
    driverGateway.login(driver_Nurdaulet);

    cout << "The driver buys water for customers!" << endl;
    comfortCar.BuyBottlesOfWater(10);

    cout << "---------------------------------------------" << endl;

    cout << "Passenger wants to get order history!" << endl;
    passengerGateway.showOrderHistory(passenger_Daniil);

    cout << "---------------------------------------------" << endl;

    cout << "Driver wants to get order history!" << endl;
    driverGateway.showOrderHistory(driver_Nurdaulet);

    cout << "---------------------------------------------" << endl;

    cout << "Driver update status!" << endl;
    driverGateway.updateStatus(driver_Nurdaulet, true);
    cout << "Driver wants see car!" << endl;
    driverGateway.showCarInfo(driver_Nurdaulet);

    cout << "---------------------------------------------" << endl;

    cout << "Situation when there no orders" << endl;
    driverGateway.showOrders(driver_Nurdaulet);

    cout << "---------------------------------------------" << endl;

    passengerGateway.orderTaxiRide(passenger_Daniil, "33/33", "100/100", passengerGateway.getOrderTime("33/33", "100/100"));
    cout << "Driver watch the list of orders!" << endl;
    driverGateway.showOrders(driver_Nurdaulet);

    cout << "---------------------------------------------" << endl;

    int orderId;
    if (driverGateway.getOrderNumber() == 1) {
        orderId = 0;
    } else {
        orderId = getRandomNumber(0 , driverGateway.getOrderNumber());
    }

    if (orderId < 0) { orderId = 0; }

    driverGateway.takeOrder(driver_Nurdaulet, passenger_Daniil, orderId);

    cout << "---------------------------------------------" << endl;

    return 0;
}

int getRandomNumber(int min, int max){ return min + rand() % (max-min); }