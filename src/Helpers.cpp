/**
 * @file Helpers.cpp
 * @brief Implements helper functions for generating random IP addresses and requests.
 */

#include <cstdlib>
#include "Helpers.h"

/**
 * @brief Generates a random IP address.
 * @return A string representing a random IP address
 */
string randomIP()
{
    return to_string(rand() % 256) + "." + to_string(rand() % 256) + "." + to_string(rand() % 256) + "." + to_string(rand() % 256);
}

/**
 * @brief Generates a random request.
 * @return A Request object with random IP addresses and processing time
 */
Request randomReq()
{
    string in = randomIP();
    string out = randomIP();
    int time = rand() % 10 + 1;
    return Request(in, out, time);
}
