/**
 * @file Loadbalancer.h
 * @brief Defines the Loadbalancer class for the load balancer simulation.
 */

#ifndef LOADBALANCER_H
#define LOADBALANCER_H

#include <vector>
#include "Webserver.h"
#include "Requestqueue.h"

using namespace std;

/**
 * @brief Class representing a load balancer.
 */
class Loadbalancer
{
private:
    vector<Webserver> servers; ///< The web servers managed by the load balancer
    Requestqueue requestQueue; ///< The request queue managed by the load balancer
    int total_time;            ///< Total time to run the load balancer

    /**
     * @brief Logs the status of the load balancer at a given cycle.
     * @param cycle The current cycle
     */
    void logStatus(int cycle);

public:
    /**
     * @brief Initializes the web servers.
     * @param num Number of web servers to initialize
     */
    void initializeServers(int num);

    /**
     * @brief Adds a request to the request queue.
     * @param req The request to add
     */
    void addRequest(Request req);

    /**
     * @brief Balances the load by assigning requests to available servers.
     */
    void balanceLoad();

    /**
     * @brief Runs the load balancer simulation.
     * @param total_time Total time to run the simulation
     */
    void run(int total_time);
};

#endif // LOADBALANCER_H
