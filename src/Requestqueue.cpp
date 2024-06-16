/**
 * @file Requestqueue.cpp
 * @brief Implements the Requestqueue class for the load balancer simulation.
 */

#include "Requestqueue.h"

/**
 * @brief Adds a request to the queue.
 * @param req The request to add
 */
void Requestqueue::addRequest(Request req)
{
    queue.push(req);
}

/**
 * @brief Retrieves the next request from the queue.
 * @return The next request
 */
Request Requestqueue::getNextRequest()
{
    Request req = queue.front();
    queue.pop();
    return req;
}

/**
 * @brief Checks if the queue is empty.
 * @return True if the queue is empty, false otherwise
 */
bool Requestqueue::isEmpty()
{
    return queue.empty();
}

/**
 * @brief Returns the current size of the queue.
 * @return The size of the queue
 */
size_t Requestqueue::size()
{
    return queue.size();
}

/**
 * @brief Returns the current queue.
 * @return A copy of the current queue
 */
queue<Request> Requestqueue::getQueue() const
{
    return queue;
}
