/**
 * @file Helpers.h
 * @brief Helper functions for generating random IP addresses and requests.
 */

#ifndef HELPERS_H
#define HELPERS_H

#include <string>
#include "Request.h"

using namespace std;

/**
 * @brief Generates a random IP address.
 * @return A string representing a random IP address.
 */
string randomIP();

/**
 * @brief Generates a random request.
 * @return A Request object with random IP addresses and processing time.
 */
Request randomReq();

#endif // HELPERS_H
