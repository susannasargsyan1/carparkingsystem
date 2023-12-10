#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/**
 * @struct Vehicle
 * @brief Structure to store information about a parked vehicle.
 */
struct Vehicle
{
    int number;             /**< Car number */
    struct tm *arrivalTime; /**< Arrival time of the car */
    struct tm *departureTime; /**< Departure time of the car */
};

struct Vehicle *parkingLot[10]; /**< Array to represent parking slots for cars */
int totalCarsParked = 0;        /**< Total number of cars parked */

/**
 * @brief Handles the arrival of a car, allocates memory, and parks the car.
 */
void arrival()
{
    if (totalCarsParked < 10)
    {
        int carNumber;
        printf("Enter car number: ");
        scanf("%d", &carNumber);

        struct Vehicle *car = (struct Vehicle *)malloc(sizeof(struct Vehicle));
        if (!car)
        {
            fprintf(stderr, "Memory allocation error.\n");
            exit(EXIT_FAILURE);
        }

        car->number = carNumber;
        car->arrivalTime = localtime(&(time_t){time(NULL)});
        car->departureTime = NULL;

        for (int i = 0; i < 10; i++)
        {
            if (!parkingLot[i])
            {
                parkingLot[i] = car;
                totalCarsParked++;
                printf("Car %d has been parked at slot %d.\n", car->number, i + 1);
                break;
            }
        }
    }
    else
    {
        printf("Parking lot is full. Cannot park more cars.\n");
    }
}

/**
 * @brief Displays the total number of cars parked.
 */
void displayTotalCarsParked()
{
    printf("Total number of cars parked: %d\n", totalCarsParked);
}

/**
 * @brief Shows the order and arrival times of parked cars.
 */
void displayParkedOrder()
{
    printf("Order in which cars are parked:\n");
    for (int i = 0; i < 10; i++)
    {
        if (parkingLot[i])
        {
            printf("Slot %d: Car %d (Arrival Time: %d:%d:%d)\n", i + 1, parkingLot[i]->number,
                   parkingLot[i]->arrivalTime->tm_hour, parkingLot[i]->arrivalTime->tm_min, parkingLot[i]->arrivalTime->tm_sec);
        }
    }
}

/**
 * @brief Handles the departure of a car, calculates parking duration, and frees up memory.
 */
void departure()
{
    int carNumber;
    printf("Enter car number for departure: ");
    scanf("%d", &carNumber);

    for (int i = 0; i < 10; i++)
    {
        if (parkingLot[i] && parkingLot[i]->number == carNumber)
        {
            time_t currentTime;
            time(&currentTime);
            double duration = difftime(currentTime, mktime(parkingLot[i]->arrivalTime));

            printf("Car %d departed from slot %d. Parking duration: %.2f seconds.\n", carNumber, i + 1, duration);

            // Record departure time
            parkingLot[i]->departureTime = localtime(&currentTime);

            free(parkingLot[i]);
            parkingLot[i] = NULL;
            totalCarsParked--;

            return;
        }
    }

    printf("Car with number %d is not found in the parking lot.\n", carNumber);
}

/**
 * @brief Displays the history of vehicle arrivals and departures.
 */
void checkHistory()
{
    printf("Parking history:\n");
    for (int i = 0; i < 10; i++)
    {
        if (parkingLot[i] && parkingLot[i]->departureTime)
        {
            printf("Slot %d: Car %d (Arrival Time: %d:%d:%d, Departure Time: %d:%d:%d)\n",
                   i + 1, parkingLot[i]->number,
                   parkingLot[i]->arrivalTime->tm_hour, parkingLot[i]->arrivalTime->tm_min, parkingLot[i]->arrivalTime->tm_sec,
                   parkingLot[i]->departureTime->tm_hour, parkingLot[i]->departureTime->tm_min, parkingLot[i]->departureTime->tm_sec);
        }
    }
}

/**
 * @brief Main function containing the program loop, user interface, and menu-driven functionality.
 * @return 0 on successful execution
 */
int main()
{
    int choice;
    do
    {
        printf("\n1. Arrival of a car\n");
        printf("2. Total no. of cars parked\n");
        printf("3. Display order in which cars are parked\n");
        printf("4. Departure of car\n");
        printf("5. Check History\n");
        printf("6. Exit\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            arrival();
            break;

        case 2:
            displayTotalCarsParked();
            break;

        case 3:
            displayParkedOrder();
            break;

        case 4:
            departure();
            break;

        case 5:
            checkHistory();
            break;

        case 6:
            // Exit the program
            printf("Exiting the program.\n");
            break;

        default:
            printf("Invalid choice. Please enter a valid option.\n");
        }

    } while (choice != 6);

    // Free memory for remaining parked cars
    for (int i = 0; i < 10; i++)
    {
        if (parkingLot[i])
        {
            free(parkingLot[i]);
        }
    }
    return 0;
}