#ifndef REQUEST_H
#define REQUEST_H

enum class RequestType { Internal, ExternalUp, ExternalDown };

class Request {
private:
    int floor;
    RequestType type;

public:
    Request(int floor, RequestType type)
        : floor(floor), type(type) {
    }

    int GetFloor() const { return floor; }
    RequestType GetType() const { return type; }
};

#endif
