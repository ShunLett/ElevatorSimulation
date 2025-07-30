// Elevator.cpp
#include <iostream>
#include "Elevator.h"
using namespace std;

void Elevator::SetWalk(bool setWalk) {
    walk = setWalk;
}

bool Elevator::GetWalk() const {
    return walk;
}

void UpAndDown::Direction(int floors, int direction, int current) {
    int floorCounter = current;
    if (floors == current) {
        cout << "Already on the floor" << endl;
        SetWalk(false);
        return;
    }
    if (direction == 1 && floors < current) {
        cout << "Invalid Input" << endl;
        SetWalk(false);
        return;
    }
    if (direction == 0 && floors > current) {
        cout << "Invalid Input" << endl;
        SetWalk(false);
        return;
    }

    cout << "......" << endl;
    cout << "Doors Opening . . ." << endl;
    cout << "......." << endl;
    cout << "Doors Closing . . ." << endl;

    if (direction == 1) {
        cout << "Traveling up to " << floors << endl;
        for (int i = current + 1; i <= floors; ++i) {
            cout << "Floor: " << i << " " << endl;
        }
    }
    else {
        cout << "Traveling down to " << floors << endl;
        for (int i = current - 1; i >= floors; --i) {
            cout << "Floor: " << i << " " << endl;
        }
    }

    cout << "......." << endl;
    cout << "Arrived. You are currently on " << floors << endl;
    SetWalk(true);
}
