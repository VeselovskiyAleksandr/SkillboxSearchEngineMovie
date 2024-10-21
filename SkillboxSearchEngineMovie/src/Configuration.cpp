#include "Configuration.h"
#include <iostream>
#include <string>
#include <map>
#include "Counter.cpp"

using namespace std;

template <class T> int Counter <T>::counter(0);
 struct Configuration :Counter<Configuration>
{
	string name;//Содержит название движка
	string version;//версия движка
	string maxResponses;//предельное  количество ответов на один запрос
	map<int, string> movieTitles;
};