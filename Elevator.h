// Elevator.h
#ifndef ELEVATOR_H
#define ELEVATOR_H

class Elevator {
public:
    bool walk;
    virtual void Direction(int floor, int direction, int current) = 0;
    void SetWalk(bool setWalk);
    bool GetWalk() const;
};

class UpAndDown : public Elevator {
public:
    void Direction(int floors, int direction, int current) override;
};

#endif
