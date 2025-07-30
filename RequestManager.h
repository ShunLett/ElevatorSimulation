#ifndef REQUESTMANAGER_H
#define REQUESTMANAGER_H

#include "Request.h"
#include <queue>
#include <vector>
#include <mutex>

class RequestManager {
private:
    std::queue<Request> requests;
    std::mutex mtx; // for thread safety if needed

public:
    void AddRequest(const Request& req) {
        std::lock_guard<std::mutex> lock(mtx);
        requests.push(req);
    }

    bool HasRequest() {
        std::lock_guard<std::mutex> lock(mtx);
        return !requests.empty();
    }

    Request GetNextRequest() {
        std::lock_guard<std::mutex> lock(mtx);
        if (requests.empty())
            return Request(-1, RequestType::Internal); // dummy
        Request req = requests.front();
        requests.pop();
        return req;
    }
};

#endif
