/**
 * @file Request.cpp
 * @brief Implements the Request structure for the load balancer simulation.
 */

#include "Request.h"

/**
 * @brief Constructor to initialize a Request object.
 * @param in IP address of the requester
 * @param out IP address of the responder
 * @param time Time required to process the request
 */
Request::Request(string in, string out, int time) : in(in), out(out), time(time) {}
