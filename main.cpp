// main.cpp
#include <iostream>
#include "Elevator.h"
using namespace std;

int main() {
    int userFloor = 5;
    while (true) {
        cout << "Enter the number of floors you want in the building:  Enter the digit ";
        cin >> userFloor;
        if (userFloor >= 5 && userFloor <= 10) break;
        cout << "Error" << endl;
    }

    int currentFloor = 1;
    int direction;
    int floors;
    UpAndDown elevator;

    cout << "The Daisy Building" << endl;
    cout << "You are currently on " << currentFloor << endl;

    while (true) {
        cout << "Enter 1 for up, 0 for down, or -5 for exit: ";
        cin >> direction;

        if (direction == -5) {
            cout << "Goodbye!" << endl;
            break;
        }

        if (direction != 0 && direction != 1) {
            cout << "Error: Invalid direction number" << endl;
            continue;
        }

        cout << "Enter floor number (1-" << userFloor << "): ";
        cin >> floors;

        if (floors < 1 || floors > userFloor) {
            cout << "Error" << endl;
            continue;
        }

        elevator.Direction(floors, direction, currentFloor);

        if (elevator.GetWalk()) {
            currentFloor = floors;
        }
    }

    return 0;
}
