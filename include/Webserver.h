#ifndef WEBSERVER_H
#define WEBSERVER_H

#include "Request.h"

class Webserver
{
public:
    bool is_busy;
    int remaining_time;
    Webserver();
    void processRequest(Request req);
    bool isAvailable();
    void cycle();
};

#endif