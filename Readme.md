# Building and Running


Run following command to build the project:

```
cmake --build --target HW4_NoskovNikita
```

# Project structure

Project contains three main source files: `main.cpp, PassengerGateway.cpp, DriverGateway.cpp, MobileApp` and

Other files are needed for subclasses.

`Main.cpp` contains the test cases for the program, to demonstrate implemented methods

`PassengerGateway.cpp` contains implementation of the methods responsible for passenger and gateway interaction.

`DriverGateway.cpp` contains implementation of the methods responsible for driver and gateway interaction.

`Mobile App` class is the part of the system which connects gateways to allow driver-passenger interaction.

# Users

Class `Passenger` has following fields:
* **name** - Name of the Passenger, also temporary used as unique identifier.

Class `Driver` has following fields:
* **car** - this driver's car.
* **name** - name of a driver.
* **status** - current status (free or in a ride).

###Car types:

In ascending order:

Ecomomy ---> Comfort ---> ComfortPlus ---> Business

Type | Free Water | Park in front of intrance
------------- | ------------- | --------------
Ecomomy | - | -
Comfort  | +| -
ComfortPlus  | +|-
Business | -|+

### Usage
Run the application and check console output, there is a demonstration of methods implemented in this version
