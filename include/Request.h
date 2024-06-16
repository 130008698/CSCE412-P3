/**
 * @file Request.h
 * @brief Defines the Request structure for the load balancer simulation.
 */

#ifndef REQUEST_H
#define REQUEST_H

#include <string>

using namespace std;

/**
 * @brief Structure representing a request in the load balancer.
 */
struct Request
{
    string in;  ///< IP address of the requester
    string out; ///< IP address of the responder
    int time;   ///< Time required to process the request

    /**
     * @brief Constructor to initialize a Request object.
     * @param in IP address of the requester
     * @param out IP address of the responder
     * @param time Time required to process the request
     */
    Request(string in, string out, int time);
};

#endif // REQUEST_H
