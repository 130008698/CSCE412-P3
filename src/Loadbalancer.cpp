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
 * @brief Dynamically adjusts the number of web servers based on the queue size.
 */
int Loadbalancer::adjustServers()
{
    int result = 0;
    if (requestQueue.size() > servers.size() * 10)
    {
        // Add a new server if the queue size exceeds the upper threshold
        servers.push_back(Webserver());
        result = 1;
    }
    else if (requestQueue.size() < servers.size() && servers.size() > 1)
    {
        // Remove an idle server if the queue size falls below the lower threshold
        for (auto it = servers.begin(); it != servers.end(); ++it)
        {
            if (it->isAvailable())
            {
                servers.erase(it);
                break;
            }
        }
        result = 2;
    }
    return result;
}

/**
 * @brief Runs the load balancer simulation.
 * @param total_time Total time to run the simulation
 */
void Loadbalancer::run(int total_time)
{
    this->total_time = total_time;
    int result = 0;
    for (int cycle = 0; cycle < total_time; cycle++)
    {
        // Add random new requests at random times
        if (rand() % 10 < 3)
        { // 30% chance to add a new request each cycle
            addRequest(randomReq());
        }

        // Adjust the number of servers based on the queue size
        if (cycle != 0)
        {
            result = adjustServers();
        }
        // Process existing requests
        balanceLoad();

        // Cycle servers
        for (auto &server : servers)
        {
            server.cycle();
        }

        // Log status
        logStatus(cycle, result);
    }
}

/**
 * @brief Logs the status of the load balancer at a given cycle.
 * @param cycle The current cycle
 */
void Loadbalancer::logStatus(int cycle, int result)
{
    std::ofstream log_file("load_balancer_log.txt", std::ios_base::app);

    if (cycle == 0)
    {
        log_file << "Range for task times: min = 1, max = 10 " << "\n";
        log_file << "Starting queue size: " << servers.size() * 100 << "\n";
    }
    log_file << "Cycle: " << cycle << "\n";
    if (result == 1)
    {
        log_file << "A new Webserver has been allocated " << "\n";
    }
    else if (result == 2)
    {
        log_file << "An idle Webserver has been deallocated " << "\n";
    }
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

    if (cycle == total_time - 1)
    {
        log_file << "Ending queue size: " << requestQueue.size() << "\n";
    }

    log_file << "\n";
    log_file.close();
}
