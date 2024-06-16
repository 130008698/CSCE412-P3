#ifndef REQUEST_H
#define REQUEST_H

#include <string>

using namespace std;

struct Request
{
    string in;
    string out;
    int time;

    Request(string in, string out, int time);
};

#endif