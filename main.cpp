#include <iostream>
#include "Loadbalancer.h"
#include "Helpers.h"

using namespace std;

int main()
{
    int num_servers, total_time;

    srand(time(0));

    cout << "Enter the number of servers: ";
    cin >> num_servers;
    cout << "Enter the total time to run load balancer: ";
    cin >> total_time;

    Loadbalancer lb;
    lb.initializeServers(num_servers);

    for (int i = 0; i < num_servers * 100; i++)
    {
        lb.addRequest(randomReq());
    }

    lb.run(total_time);
    return 0;
}