/**
 * @file Webserver.cpp
 * @brief Implements the Webserver class for the load balancer simulation.
 */

#include "Webserver.h"

/**
 * @brief Constructor to initialize a Webserver object.
 */
Webserver::Webserver() : is_busy(false), remaining_time(0) {}

/**
 * @brief Processes a new request.
 * @param req The request to process
 */
void Webserver::processRequest(Request req)
{
    is_busy = true;
    remaining_time = req.time;
}

/**
 * @brief Checks if the server is available.
 * @return True if the server is available, false otherwise
 */
bool Webserver::isAvailable()
{
    return !is_busy;
}

/**
 * @brief Simulates a clock cycle tick.
 */
void Webserver::cycle()
{
    if (is_busy)
    {
        remaining_time--;
        if (remaining_time <= 0)
        {
            is_busy = false;
        }
    }
}
