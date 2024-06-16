#ifndef REQUESTQUEUE_H
#define REQUESTQUEUE_H

#include <queue>
#include "Request.h"

using namespace std;

class Requestqueue
{
private:
    queue<Request> queue;

public:
    void addRequest(Request req);
    Request getNextRequest();
    bool isEmpty();
    size_t size();
    std::queue<Request> getQueue() const;
};

#endif