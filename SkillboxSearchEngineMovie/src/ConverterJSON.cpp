
#include <fstream>
#include <vector>
#include <exception>
#include "ConverterJSON.h"
#include "nlohmann/json.hpp"
#include "Configuration.cpp"

using namespace std;

  class ConverterJSON {
public: ConverterJSON() = default;
	  Configuration configuration;
	  vector<string> getRequests;

//функция начала работы движка
	  void start()
	  {
		  cout << "                              Launching a search engine... " << "\n";
		  nlohmann::json config;
		  ifstream cnfile("config.json");
		  if (!cnfile) {

			  throw exception();
	  }

		  for (int i = 0; i < configurationCounter<Configuration>::getConfigurationCounter(); i++)
		  {
			  cnfile >> config;
	      }
		  cout << config["config"] << "\n";
		  for (const auto& item : config["config"].items())
		  {
			  if (item.key() == "name")
			  {
				  configuration.name = item.value();
			  }
			  else if (item.key() == "version")
			  {
				  configuration.version = item.value();
			  }
			  else if (item.key() == "maxResponses")
			  {
				  configuration.maxResponses = item.value();
			  }
		  }
		  configuration.maxRespons =stoi(configuration.maxResponses);
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

	  //функция проверки открытия файла
	  void openFile(string path)
	  {
		  if (FileIsExist(path))
		  {
			  ofstream file;
			  file.open(path, std::ofstream::out | std::ofstream::trunc);
			  file.close();
		  }
		  else
		  {
			  ofstream reqFile(path);
			  reqFile.close();
		  }
	  };
	  
//функция ввода запроса
	  void requerysInputFunction(vector<string>& getRequests)
//	  void requerysInputFunction()
	  {
		  cout << "\n" << "                                      Information about domestic and foreign films" << "\n" << "\n";
		  cout << "               Search query field" << "\n" << "\n";
		  string requerie = "";
		  getline(cin, requerie);
		  if (requerie.length() > configuration.maxStrRequestLength)
	      requerie.erase(requerie.length() - configuration.maxStrRequestLength);
		  cout << "\n";
		  getRequests.push_back(requerie);
		  requerie = "";
		  ofstream reqfile("requests.json");
		  nlohmann::json reqconfig;
		  reqconfig["number"] = getRequests.size();
		  reqconfig["request"] = getRequests[getRequests.size() - 1];
		  reqfile << reqconfig;
		  reqfile.close();
	  }

	  //функция поиска ответов

	  void searchAnswersFunction()
	  {
		  for (int i = 0; i < getRequests.size(); ++i)
		  {
			  static const int bufferValue = configuration.filesValue;
			  char movieBuffer[bufferValue];
			  multimap<int, string> searchResult;
			  for (auto it = configuration.movieTitles.begin(); it != configuration.movieTitles.end(); ++it)
			  {
				  string moviePath = it->second;
				  ifstream file;
				  file.open(moviePath);
				  file.seekg(0);
				  if (!file.is_open())
				  {
					  cerr << "\n" << "The file is not found." << "\n";
				  }

				  ifstream requestFile("requests.json");
				  nlohmann::json configr;

				  for (int i = 0; i < configurationCounter<Configuration>::getConfigurationCounter(); i++)
				  {
					  requestFile >> configr;
				  }
				  requestFile.close();
				  string strRequest = configr["request"];
				  const char* cstrRequest = strRequest.c_str();
				  int coincidCounter = 0;
				  int posRequest = 0;
				  int lenRequest = strRequest.length();
				  int lenBuffer = configuration.filesValue;
				  while (file)
				  {
					  int fileSize = sizeof(movieBuffer);
					  fill(movieBuffer, movieBuffer + fileSize, 0);
					  file.read(movieBuffer, sizeof(movieBuffer) - 1);
					  cout << "\n";
					  cout << movieBuffer;

					  for (int posBuffer = 0; posBuffer < lenBuffer - lenRequest; ++posBuffer)
					  {
						  if (movieBuffer[posBuffer] == cstrRequest[posRequest])
						  {
							  posRequest++;
							  if (posRequest == lenRequest)
							  {
								  coincidCounter++;
							  }

						  }
						  else
						  {
							  posBuffer -= posRequest;
							  posRequest = 0;
						  }
					  }
				  }
				  searchResult.insert({ coincidCounter, moviePath });
				  coincidCounter = 0;
				  if (movieBuffer[file.gcount()])
				  {
					  break;
				  }
				  file.close();
			  }
			  int countResponses = 0;
			  for (auto it = searchResult.crbegin(); it != searchResult.crend(); ++it)
			  {
				  if (countResponses < configuration.maxRespons)
				  {
					  if (it->first > 0)
						  cout << "\n" << it->first << " " << it->second;
				  }
				  else
				  {
					  searchResult.clear();
					  break;
				  }

				  countResponses++;
			  }
		  }
	  }


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
