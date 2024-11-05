#include <iostream>
#include <string>
#include <fstream>
#include <map>
#include <vector>
#include <exception>
#include "ConverterJSON.h"
#include "nlohmann/json.hpp"
#include <windows.h>
#include "Configuration.cpp"

using namespace std;

  class ConverterJSON {
public: ConverterJSON() = default;
	  Configuration configuration;
	  vector<string> GetRequests;

//функция начала работы движка
	  void start()
	  {
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
		  for (const auto& item : config["files"].items())
		  {
			  int i = stoi(item.key());
			  pair<int, string> oPair(i, item.value());
			  configuration.movieTitles.insert(oPair);
		  }
		  cnfile.close();
	  };

//функция проверки наличия файла
	  bool FileIsExist(string filePath)
	  {
		  bool isExist = false;
		  std::ifstream fin(filePath.c_str());

		  if (fin.is_open())
			  isExist = true;

		  fin.close();
		  return isExist;
	  }
	  

 
//функция ввода запроса
	  void RequerysInputFunction(vector<string>& GetRequests)
	  {
		  cout << "\n" << "                                      Information about domestic and foreign films" << "\n" << "\n";
		  cout << "               Search query field" << "\n" << "\n";
		  string requerie = "";
		  getline(cin, requerie);
		  if (requerie.length() > 80)
	      requerie.erase(requerie.length() - 80);
		  cout << "\n" << "\n";
		  GetRequests.push_back(requerie);
		  requerie = "";
		  ofstream reqfile("requests.json");
		  nlohmann::json reqconf;
		  reqconf["number"] = GetRequests.size();
		  reqconf["request"] = GetRequests[GetRequests.size() - 1];
		  reqfile << reqconf;
		  reqfile.close();
	  }

	//		  ofstream reqfile("requests.json");
			  //	  map <int, string> str;
	//		  int counter = 0;
	//		  nlohmann::json conf;
			  //		  for (const auto& item : conf["files"].items()) {
	//		  for (auto it = GetRequests.begin(); it != GetRequests.end(); ++it) {
		//		  conf["number"] = counter;
			//	  conf["request"] = GetRequests[counter];
				//  ++counter;
				  //		  int i = stoi(item.key());
					  //	  pair<int, string> oPair(i, item.value());
				  //		  str.insert(oPair);
				  //		  anfile >> conf;
	//		  }
			  //	  conf["requests"] << conf;
		//	  reqfile << conf;

		//	  reqfile.close();

	  // Метод получения содержимого файлов.
	  vector<string> GetTextDocuments()
	  {
//		
	  }
	  // Метод считывания значения max_responses
	  int GetResponsesLimit()
	  {
		  //		  return  stoi(configuration.maxResponses);
	  }
	  // Метод получения запросов
	//  vector<std::string> GetRequests();
	  //Метод сохраняет результаты поисковых запросов
	  void putAnswers(std::vector<std::vector<std::pair<int, float>>> answers)
	  {

	  }

};
