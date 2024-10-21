#include <iostream>
#include <string>
#include <fstream>
#include <map>
#include <vector>
#include <exception>
#include "Configuration.cpp"
#include "nlohmann/json.hpp"
#include "start.h"

using namespace std;
	 
 inline void start()
{
	 Configuration configuration;
	cout << "                              Launching a search engine... " << "\n";
	nlohmann::json config;
	ifstream cnfile("config.json");
	if (!cnfile) {

		throw exception();
	}

	for (int i = 0; i < Counter<Configuration>::getCounter(); i++)
	{
		cnfile >> config;
	}
	cout << config["config"] << "\n";
	for (const auto& item : config["files"].items()) {
		int i = stoi(item.key());
		pair<int, string> oPair(i, item.value());
		configuration.movieTitles.insert(oPair);
	}
	for (auto it = configuration.movieTitles.begin(); it != configuration.movieTitles.end(); ++it)
					cout << it->second << '\n'; 
	cnfile.close();
};