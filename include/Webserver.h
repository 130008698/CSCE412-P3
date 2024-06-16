#ifndef WEBSERVER_H
#define WEBSERVER_H

#include "Request.h"

class Webserver
{
private:
    bool is_busy;
    int remaining_time;

public:
    Webserver();
    void processRequest(Request req);
    bool isAvailible();
    void tick();
}

#endif