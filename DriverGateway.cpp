

#include "DriverGateway.h"

#include <fstream>
#include <ctime>
#include <cmath>

using namespace std;

bool DriverGateway::login(Driver driver) {
    cout << "The driver " << driver.getName() << " tries to enter the application..." << endl;
    return app.authentication(move(driver));
}

size_t getTokens(const std::string &txt, std::vector<std::string> &strs, char ch)
{
    size_t pos = txt.find( ch );
    size_t initialPos = 0;
    strs.clear();

    while( pos != std::string::npos ) {
        strs.push_back( txt.substr( initialPos, pos - initialPos ) );
        initialPos = pos + 1;

        pos = txt.find( ch, initialPos );
    }

    strs.push_back( txt.substr( initialPos, std::min( pos, txt.size() ) - initialPos + 1 ) );

    return strs.size();
}

void DriverGateway::showOrderHistory(Driver driver) {
    if (!checkAuth(driver)) {return;}

    cout << "Getting order history..." << endl;
    vector<string> orderHistory =  app.getOrderHistory(driver);
    if (orderHistory.empty()) {
        cout << "Order history is empty!" << endl;
    }

    cout << "Order history of the " << driver.getName() << " driver:" << endl;
    for(int i = 0; i < orderHistory.size(); i++) {
        vector<string> tokens;
        getTokens(orderHistory[i], tokens, ' ');
        cout << "Order #" << i+1 << endl;
        cout << "From " << tokens[0] << " to " << tokens[1] << endl;
        cout << "Payment method: ";
        if(tokens[2] == "card:") {
            cout << "card" << endl;
            cout << "Card number: " << tokens[3] << endl;
        } else {
            cout << "cash" << endl;
        }
    }
}

void DriverGateway::updateStatus(Driver driver, bool status) {
    if (!checkAuth(driver)) {return;}

    if(status) {
        cout << "Driver " << driver.getName() << " is online!" << endl;
    } else {
        cout << "Driver " << driver.getName() << " is offline!" << endl;
    }

    app.setStatus(move(driver), status);
}

void DriverGateway::showCarInfo(Driver driver) {
    if (!checkAuth(driver)) {return;}

    cout << "Car information!" << endl;
    cout << "Model: " << driver.car.getModel() << endl;
    cout << "Number: " << driver.car.getNumber() << endl;
    cout << "Car Type: " << driver.car.getCarType() << endl;
    cout << "Color: " << driver.car.getColor() << endl;
}

void DriverGateway::getOrders() {
    orders = app.getOrders();
}

void DriverGateway::showOrders(Driver driver) {
    if (!checkAuth(driver)) {return;}

    getOrders();

    if (orders.empty()) {
        cout << "There no available orders!" << endl;
        return;
    }
    cout << "Available orders" << endl;

    for(int i = 0; i < orders.size(); i++) {
        vector<string> fromPos;
        vector<string> toPos;
        getTokens(orders[i][1], fromPos, '/');
        getTokens(orders[i][2], toPos, '/');
        int x = stoi(toPos[0]) - stoi(fromPos[0]);
        int y = stoi(toPos[1]) - stoi(fromPos[1]);
        double length = sqrt(x*x + y*y);
        double cost;
        switch (driver.car.carType) {
            case 1:
                cost = length*0.5;
                break;
            case 2:
                cost = length;
                break;
            case 3:
                cost = length*1.5;
                break;
            case 4:
                cost = length*2;
        }

        cout << "Order #" << i+1 << endl;
        cout << "Client name: " << orders[i][0] << endl;
        cout << "From: " << orders[i][1] << endl;
        cout << "To: " << orders[i][2] << endl;
        cout << "Time: " << orders[i][3] << endl;
        cout.precision(3);
        cout << "Cost: " << cost << "$" << endl;
    }
}

bool DriverGateway::checkAuth(Driver driver) {
    if (!app.checkDriverAuth(driver)) {
        cout << "Driver " << driver.getName() << " is not logged in!" << endl;
        return false;
    }
    return true;
}

int getRandomNm(int min, int max){ return min + rand() % max; }

void DriverGateway::takeOrder(Driver driver, Passenger passenger ,int orderId) {
    app.activeOrders.push_back(orders[orderId]);
    app.orders.erase(app.orders.begin() + orderId);
    driver.setStatus(false);
    cout << "Driver " << driver.getName() << " take the order!" << endl;
    cout << "Order information:" << endl;
    cout << "Client name: " << orders[orderId][0] << endl;
    cout << "From: " << orders[orderId][1] << endl;
    cout << "To: " << orders[orderId][2] << endl;
    cout << "Approximate time: " << orders[orderId][3] << endl;

    vector<string> fromPos;
    vector<string> toPos;
    getTokens(orders[orderId][1], fromPos, '/');
    getTokens(orders[orderId][2], toPos, '/');
    int x = stoi(toPos[0]) - stoi(fromPos[0]);
    int y = stoi(toPos[1]) - stoi(fromPos[1]);
    double length = sqrt(x*x + y*y);


    cout << "Order execution!" << endl;

    time_t pref_timestart = time(0);
    vector<string> time;
    getTokens(orders[orderId][3], time, ':');
    int seconds = stoi(time[0])*60 + stoi(time[1]);
    int pref_timeduration;
    bool once = true;
    int randomTime = getRandomNm(1, seconds-1);
    do {
        time_t pref_timefinish = std::time(0);
        pref_timeduration = pref_timefinish - pref_timestart;
        if(pref_timeduration == randomTime && once) {
            cout << "Passenger wants get current coordinates!" << endl;
            double angle = asin(stod(fromPos[0])/length);
            double partOfLength = (length/seconds)*pref_timeduration;
            x = sin(angle) * partOfLength + stoi(fromPos[0]);
            y = cos(angle) * partOfLength + stoi(fromPos[1]);

            cout << "Current coordinates: " << x << "/" << y << endl;
            once = false;
        }
    } while (pref_timeduration < seconds);

    cout << "Client delivered!" << endl;

    if (orders.size() == 1) {
        orders.pop_back();
    } else {
        app.orders.erase(app.orders.begin() + orderId);
    }
}

int DriverGateway::getOrderNumber() {
    return orders.size();
}