Car Parking Distance Control System

Overview:This project implements a simple console-based Car Parking Distance Control System in C. The system allows users to manage the arrival and departure of vehicles in a parking lot. It tracks information such as car number, arrival time, and departure time.

Features
Car Arrival: Users can input the car number, and the system will park the car in the first available slot, recording the arrival time.
Total Cars Parked: Displays the total number of cars currently parked in the lot.
Display Parked Order: Shows the order in which cars are parked, along with their arrival times.
Car Departure: Users can specify a car number for departure, and the system calculates and displays the parking duration before freeing up the slot.
Check History:  Placeholder for future functionality to check the history of arrivals and departures.
Exit: Allows users to exit the program.

Code Structure
Constants: Definitions for constant values like CAR.
Structs: Defines the Vehicle struct to store car information.
Global Variables: Declaration of the parking lot array and a counter for total cars parked.

Functions:
arrival(): Handles the arrival of a car, allocates memory, and parks the car.
displayTotalCarsParked(): Displays the total number of cars parked.
displayParkedOrder(): Shows the order and arrival times of parked cars.
departure(): Handles the departure of a car, calculates parking duration, and frees up memory.
checkHistory(): Placeholder for future implementation of history checking.

Main Function: Contains the main program loop, user interface, and menu-driven functionality.

Dependencies
Standard C libraries: stdio.h, stdlib.h,  time.h.

Note
The history-checking feature is not implemented in this example and serves as a placeholder for future enhancements.
The code includes memory deallocation for remaining parked cars before exiting.

License
This project is licensed under the MIT License. Feel free to use and modify the code according to your needs.


