/**
 * @file Loadbalancer.cpp
 * @brief Implements the Loadbalancer class for the load balancer simulation.
 */

#include <fstream>
#include "Loadbalancer.h"
#include "Helpers.h"

/**
 * @brief Initializes the web servers.
 * @param num_servers Number of web servers to initialize
 */
void Loadbalancer::initializeServers(int num_servers)
{
    for (int i = 0; i < num_servers; i++)
    {
        servers.push_back(Webserver());
    }
}

/**
 * @brief Adds a request to the request queue.
 * @param req The request to add
 */
void Loadbalancer::addRequest(Request req)
{
    requestQueue.addRequest(req);
}

/**
 * @brief Balances the load by assigning requests to available servers.
 */
void Loadbalancer::balanceLoad()
{
    for (auto &server : servers)
    {
        if (server.isAvailable() && !requestQueue.isEmpty())
        {
            server.processRequest(requestQueue.getNextRequest());
        }
    }
}

/**
 * @brief Runs the load balancer simulation.
 * @param total_time Total time to run the simulation
 */
void Loadbalancer::run(int total_time)
{
    this->total_time = total_time;
    for (int cycle = 0; cycle < total_time; cycle++)
    {
        // Add random new requests at random times
        if (rand() % 10 < 3)
        { // 30% chance to add a new request each cycle
            addRequest(randomReq());
        }

        // Process existing requests
        balanceLoad();

        // Cycle servers
        for (auto &server : servers)
        {
            server.cycle();
        }

        // Log status
        logStatus(cycle);
    }
}

/**
 * @brief Logs the status of the load balancer at a given cycle.
 * @param cycle The current cycle
 */
void Loadbalancer::logStatus(int cycle)
{
    std::ofstream log_file("load_balancer_log.txt", std::ios_base::app);

    if (cycle == 0)
    {
        log_file << "Range for task times: min = 1, max = 10 " << "\n";
        log_file << "Starting queue size: " << servers.size() * 1000 << "\n";
    }
    log_file << "Cycle: " << cycle << "\n";

    // Log server statuses
    for (size_t i = 0; i < servers.size(); i++)
    {
        log_file << "Server " << i << ": "
                 << (servers[i].isAvailable() ? "Available" : "Busy")
                 << ", Remaining Time: " << (servers[i].isAvailable() ? 0 : servers[i].remaining_time) << "\n";
    }

    // Log request queue status
    log_file << "Queue size: " << requestQueue.size() << "\n";
    log_file << "Requests in Queue:\n";
    std::queue<Request> tempQueue = requestQueue.getQueue();
    while (!tempQueue.empty())
    {
        Request req = tempQueue.front();
        log_file << "  Request - IP In: " << req.in << ", IP Out: " << req.out << ", Time: " << req.time << "\n";
        tempQueue.pop();
    }

    if (cycle == total_time)
    {
        log_file << "Ending queue size: " << requestQueue.size() << "\n";
    }

    log_file << "\n";
    log_file.close();
}
