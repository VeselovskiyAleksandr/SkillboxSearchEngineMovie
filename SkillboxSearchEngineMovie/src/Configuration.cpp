#include "Configuration.h"
#include <iostream>
#include <string>
#include <map>
#include "Counter.cpp"

using namespace std;

template <class T> int Counter <T>::counter(0);
 struct Configuration :Counter<Configuration>
{
	string name;//�������� �������� ������
	string version;//������ ������
	string maxResponses;//����������  ���������� ������� �� ���� ������
	map<int, string> movieTitles;
};