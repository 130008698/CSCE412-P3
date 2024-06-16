/**
 * @file Requestqueue.h
 * @brief Defines the Requestqueue class for the load balancer simulation.
 */

#ifndef REQUESTQUEUE_H
#define REQUESTQUEUE_H

#include <queue>
#include "Request.h"

using namespace std;

/**
 * @brief Class representing a queue of requests.
 */
class Requestqueue
{
private:
    queue<Request> queue; ///< The request queue

public:
    /**
     * @brief Adds a request to the queue.
     * @param req The request to add
     */
    void addRequest(Request req);

    /**
     * @brief Retrieves the next request from the queue.
     * @return The next request
     */
    Request getNextRequest();

    /**
     * @brief Checks if the queue is empty.
     * @return True if the queue is empty, false otherwise
     */
    bool isEmpty();

    /**
     * @brief Returns the current size of the queue.
     * @return The size of the queue
     */
    size_t size();

    /**
     * @brief Returns the current queue.
     * @return A copy of the current queue.
     */
    std::queue<Request> getQueue() const;
};

#endif // REQUESTQUEUE_H
