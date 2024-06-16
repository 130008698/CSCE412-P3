#include <cstdlib>
#include "Helpers.h"

string randomIP()
{
    return to_string(rand() % 256) + "." + to_string(rand() % 256) + "." + to_string(rand() % 256) + "." + to_string(rand() % 256);
}

Request randomReq()
{
    string in = randomIP();
    string out = randomIP();
    int time = rand() % 10 + 1;
    return Request(in, out, time);
}