// SkillboxSearchEngineMovie.cpp: определяет точку входа для приложения.
#include <iostream>
#include <string>
#include <fstream>
#include "SkillboxSearchEngineMovie.h"
#include <exception>
#include "ConverterJSON.cpp"
//#include "start.cpp"
//#include "Configuration.cpp"

using namespace std;
int main()
{
	ConverterJSON converterJSON;
	// Configuration configuration;
	try
	{
	//	converterJSON.start();
	//	 start();
	}
	catch (const exception& x)
	{
		cerr << "The file is not found.";
		return 1;
	}
//	for (auto it = converterJSON.configuration.movieTitles.begin();it!= converterJSON.configuration.movieTitles.end();++it)
//	for (auto it = configuration.movieTitles.begin(); it != configuration.movieTitles.end(); ++it)
//			cout << it->second << '\n'; 
	if (converterJSON.FileIsExist("answers.json"))
	{
		ofstream ofs;
		ofs.open("answers.json", std::ofstream::out | std::ofstream::trunc);
		ofs.close();
	}
	else
	{
		ofstream ofs("answers.json");
		ofs.close();
	}
	converterJSON.inputFieldImageFunction(converterJSON.x0, converterJSON.y0);
	converterJSON.RequerysInputFunction(converterJSON.GetRequests, &converterJSON.x0, &converterJSON.y0);
	return 0;
}
