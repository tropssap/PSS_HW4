###About
This project is a taxi system where drivers can take an order and customers can get to a 
certain place. I used text files as a database. The user text file reflects the drivers 
and passengers who use the application. This file permanently stores information, even when 
the program is not running. The orders text file is a list of orders that appear while the 
application is running. Each user must log into the application and as they work with this 
application, authentication is checked so that there are no unauthorized logins. Passenger 
and driver can get information about past orders. The address system is a two-dimensional 
coordinate system (x, y). The addresses are represented by 2 coordinates that reflect the 
point in the given coordinate system. The program uses a number randomizer to create unique 
situations. For example, during the late afternoon, a passenger requests water and his 
current position at a random moment in time.

###Building
- cmake minimum required (VERSION 3.17)
- Version of compiler is C++20

####Case 1:

You should run a command in console for creating .exe file
```
cmake ./
```

####Case 2:

You should open folder as a project in CLion and run program throw build-in compiler