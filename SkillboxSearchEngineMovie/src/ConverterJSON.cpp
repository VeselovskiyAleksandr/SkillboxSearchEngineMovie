#include <iostream>
#include <string>
#include <fstream>
#include <map>
#include <vector>
#include <exception>
#include "ConverterJSON.h"
#include "nlohmann/json.hpp"
#include <windows.h>
#include  "start.cpp"

using namespace std;

  class ConverterJSON {
public: ConverterJSON() = default;

	  vector<string> GetRequests;

	  start();
	//  void functions:: start();
//	  {
//		  cout << "                              Launching a search engine... " << "\n";
//		  nlohmann::json config;
//		  ifstream cnfile("config.json");
//		  if (!cnfile) {

//			  throw exception();
//		  }

//		  for (int i = 0; i < Counter<Configuration>::getCounter(); i++)
//		  {
//			  cnfile >> config;
//		  }
//		  cout << config["config"] << "\n";
//		  for (const auto& item : config["files"].items()) {
//			  int i = stoi(item.key());
//			  pair<int, string> oPair(i, item.value());
//			  configuration.movieTitles.insert(oPair);
//		  }
//		  cnfile.close();
//	  };

	  bool FileIsExist(string filePath)
	  {
		  bool isExist = false;
		  std::ifstream fin(filePath.c_str());

		  if (fin.is_open())
			  isExist = true;

		  fin.close();
		  return isExist;
	  }
	  

	  //функция установки курсора в заданное положение
	  void gotoxy(short x, short y)
	  {
		  HANDLE StdOut = GetStdHandle(STD_OUTPUT_HANDLE);
		  COORD  coord = { x, y };
		  SetConsoleCursorPosition(StdOut, coord);
	  }

	  short x0 = 0, y0 = 0;
	  //функция отображения поля ввода с курсором
	  void inputFieldImageFunction(short& x0, short& y0) {
		  cout << "\n" << "                                      Information about domestic and foreign films" << "\n" << "\n";
		  cout << "               Search query field" << "\n" << "\n";
		  char ch1 = 61;
		  for (int i = 0; i < 150; ++i)
			  cout << ch1;
		  cout << "\n";
		  //вывод положения курсора
		  CONSOLE_SCREEN_BUFFER_INFO bi;
		  GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &bi);
		  x0 = bi.dwCursorPosition.X;
		  y0 = bi.dwCursorPosition.Y;
		  //	  *x0 = x, *y0 = y;
		  cout << "\n";
		  for (int i = 0; i < 150; ++i)
			  cout << ch1;
		  cout << "\n";
	  }
	  void RequerysInputFunction(vector<string>& GetRequests, short* x0, short* y0)
	  {
		  string requerie = "";
		  bool inputCheck = false;
		  gotoxy(*x0, *y0);
		  getline(cin, requerie);
		  if (requerie.length() > 80)
			  requerie.erase(requerie.length() - 80);
		  gotoxy(*x0, *y0);
		  cout << "\n" << "\n";
		  GetRequests.push_back(requerie);
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
