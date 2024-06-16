/**
 * @file Webserver.h
 * @brief Defines the Webserver class for the load balancer simulation.
 */

#ifndef WEBSERVER_H
#define WEBSERVER_H

#include "Request.h"

/**
 * @brief Class representing a web server in the load balancer simulation.
 */
class Webserver
{
public:
    bool is_busy;       ///< Indicates if the server is busy
    int remaining_time; ///< Remaining time to complete the current request

    /**
     * @brief Constructor to initialize a Webserver object.
     */
    Webserver();

    /**
     * @brief Processes a new request.
     * @param req The request to process
     */
    void processRequest(Request req);

    /**
     * @brief Checks if the server is available.
     * @return True if the server is available, false otherwise
     */
    bool isAvailable();

    /**
     * @brief Simulates a clock cycle tick.
     */
    void cycle();
};

#endif // WEBSERVER_H
