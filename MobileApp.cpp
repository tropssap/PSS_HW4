

#include "MobileApp.h"

#include <fstream>
#include <iostream>
#include <algorithm>
#include <utility>

using namespace std;

static inline void ltrim(std::string &s) {
    s.erase(s.begin(), std::find_if(s.begin(), s.end(), [](unsigned char ch) {
        return !std::isspace(ch);
    }));
}

static inline void rtrim(std::string &s) {
    s.erase(std::find_if(s.rbegin(), s.rend(), [](unsigned char ch) {
        return !std::isspace(ch);
    }).base(), s.end());
}

static inline void trim(std::string &s) {
    ltrim(s);
    rtrim(s);
}

size_t split(const std::string &txt, std::vector<std::string> &strs, char ch)
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

MobileApp::MobileApp(string name) {
    this->name = move(name);
    ofstream ok("orders.txt", ios::trunc);

}

bool MobileApp::authentication(Passenger passenger) {
    string line;
    vector<string> tokens;
    ifstream file("users.txt");

    while (getline (file, line)) {
        split(line, tokens, ' ');
        if (tokens[1] == "1" && tokens[2] == passenger.getName()) {
            cout << "Authentication successful!" << endl;
            passengersInSystem.push_back(tokens);
            return true;
        }
    }

    cout << "Authentication failed!" << endl;
    return false;
}

vector<string> MobileApp::getOrderHistory(Passenger passenger) {
    vector<string> orderHistory;
    for(int i = 0; i < passengersInSystem.size();i++) {
        if(passengersInSystem[i][2] == passenger.getName()) {
            string order = "";
            for(int j = 4; j < passengersInSystem[i].size(); j++) {
                order = order + " " + passengersInSystem[i][j] ;
                if(passengersInSystem[i][j].find('}') != string::npos) {
                    break;
                }
            }
            order.erase(order.find('{'), 1);
            order.erase(order.find('}'), 1);
            split(order, orderHistory, ',');
            for(int j = 0; j < orderHistory.size(); j++) {
                trim(orderHistory[j]);
            }
            break;
        }
    }
    return orderHistory;
}

MobileApp::MobileApp() {}

bool MobileApp::authentication(Driver driver) {
    string line;
    vector<string> tokens;
    ifstream file("users.txt");

    while (getline (file, line)) {
        split(line, tokens, ' ');
        if (tokens[1] == "2" && tokens[2] == driver.getName()) {
            cout << "Authentication successful!" << endl;
            driversInSystem.push_back(tokens);
            return true;
        }
    }

    cout << "Authentication failed!" << endl;
    return false;
}

vector<string> MobileApp::getOrderHistory(Driver driver) {
    vector<string> orderHistory;
    for(int i = 0; i < driversInSystem.size();i++) {
        if(driversInSystem[i][2] == driver.getName()) {
            string order = "";
            for(int j = 4; j < driversInSystem[i].size(); j++) {
                order = order + " " + driversInSystem[i][j] ;
                if(driversInSystem[i][j].find('}') != string::npos) {
                    break;
                }
            }
            order.erase(order.find('{'), 1);
            order.erase(order.find('}'), 1);
            split(order, orderHistory, ',');
            for(int j = 0; j < orderHistory.size(); j++) {
                trim(orderHistory[j]);
            }
            break;
        }
    }
    return orderHistory;
}

void MobileApp::setStatus(Driver driver, bool status) {
    driver.setStatus(status);
}

bool MobileApp::getDriverStatus(Driver driver) {
    return driver.getStatus();
}

void MobileApp::addOrder(Passenger passenger, string from, string to, string time) {
    ofstream out;
    out.open("orders.txt");
    if (out.is_open()) {
        out << passenger.getName() << " " << from << " " << to << " " << time << " " << 0 << endl;
    }
}

vector<vector<string>> MobileApp::getOrders() {
    string line;
    ifstream in("orders.txt");
    if (in.is_open()) {
        while (getline(in, line)) {
            vector<string> order;
            split(line, order, ' ');
            orders.push_back(order);
        }
    }
    return orders;
}

bool MobileApp::checkDriverAuth(Driver driver) {
    if (driversInSystem.empty()) {
        cout << "Driver " << driver.getName() << " is not logged in!" << endl;
        return false;
    }

    for (auto & i : driversInSystem) {
        if (i[2] == driver.getName()) {
            return true;
        }
    }
    return false;
}