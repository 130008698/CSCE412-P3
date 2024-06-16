#include "Webserver.h"

Webserver::Webserver() : is_busy(false), remaining_time(0) {}

void Webserver::processRequest(Request req)
{
    is_busy = true;
    remaining_time = req.time;
}

bool Webserver::isAvailable()
{
    return !is_busy;
}

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