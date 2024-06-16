#ifndef LOADBALANCER_H
#define LOADBALANCER_H

#include <vector>
#include "Webserver.h"
#include "Requestqueue.h"

using namespace std;

class Loadbalancer
{
private:
    vector<Webserver> servers;
    Requestqueue requestQueue;
    int total_time;

    void logStatus(int cycle);

public:
    void initializeServers(int num);
    void addRequest(Request req);
    void balanceLoad();
    void run(int total_time);
};

#endif