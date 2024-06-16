#include "Requestqueue.h"

void Requestqueue::addRequest(Request req)
{
    queue.push(req);
}

Request Requestqueue::getNextRequest()
{
    Request req = queue.front();
    queue.pop();
    return req;
}

bool Requestqueue::isEmpty()
{
    return queue.empty();
}

size_t Requestqueue::size()
{
    return queue.size();
}

queue<Request> Requestqueue::getQueue() const
{
    return queue;
}