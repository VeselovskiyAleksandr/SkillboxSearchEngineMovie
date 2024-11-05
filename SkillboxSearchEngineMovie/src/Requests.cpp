#include "Requests.h"
#include <iostream>
#include <string>
#include <map>
#include "Counter.cpp"
using namespace std;

template <class R> int Counter <R>::counter(0);
struct Requests : Counter <Requests>
//struct Requests
{
	map<int, string> movieRequests;
};