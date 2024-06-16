#include <fstream>
#include "Loadbalancer.h"
#include "Helpers.h"

void Loadbalancer::initializeServers(int num_servers)
{
    for (int i = 0; i < num_servers; i++)
    {
        servers.push_back(Webserver());
    }
}

void Loadbalancer::addRequest(Request req)
{
    requestQueue.addRequest(req);
}

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

void Loadbalancer::logStatus(int cycle)
{
    std::ofstream log_file("load_balancer_log.txt", std::ios_base::app);

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

    log_file << "\n";
    log_file.close();
}