#include "Configuration.h"
#include <iostream>
#include <string>
#include <map>
#include "configurationCounter.cpp"

using namespace std;

template <class T> int configurationCounter <T>::counter(0);
 struct Configuration :configurationCounter<Configuration>
{
	string name;//Содержит название движка
	string version;//версия движка
	string maxResponses;//предельное  количество ответов на один запрос
	map<int, string> movieTitles;
	int maxRespons;
	static const int maxStrRequestLength = 80;
	static const int filesValue = 10000;
};