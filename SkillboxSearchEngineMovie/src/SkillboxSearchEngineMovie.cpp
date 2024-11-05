// SkillboxSearchEngineMovie.cpp: определяет точку входа для приложения.
#include <iostream>
#include <string>
#include <fstream>
#include "SkillboxSearchEngineMovie.h"
#include <exception>
#include "ConverterJSON.cpp"
#include "nlohmann/json.hpp"
#include <sstream>
#include <filesystem>
using namespace std;
 namespace fs= filesystem;

int main()
{
	ConverterJSON converterJSON;
	try
	{
		converterJSON.start();
	}
	catch (const exception& x)
	{
		cerr << "The file is not found.";
		return 1;
	}
	for (auto it = converterJSON.configuration.movieTitles.begin();it!= converterJSON.configuration.movieTitles.end();++it)
			cout << it->second << '\n'; 
	if (converterJSON.FileIsExist("requests.json"))
	{
		ofstream ofs;
		ofs.open("requests.json", std::ofstream::out | std::ofstream::trunc);
		ofs.close();
	}
	else
	{
		ofstream ofs("requests.json");
		ofs.close();
	}
	converterJSON.RequerysInputFunction(converterJSON.GetRequests);
	ifstream reqfs("requests.json");
	nlohmann::json configr;
	for (int i = 0; i < Counter<Configuration>::getCounter(); i++)
	{
		reqfs >> configr;
		cout << configr["request"]<<" "<< configr["number"] << "!!!\n";
	}
	reqfs.close();
	//здесь файл не открывается
	for (auto it = converterJSON.configuration.movieTitles.begin(); it != converterJSON.configuration.movieTitles.end(); ++it)
	{
		string str = "";
		ifstream file(it->second);
		if (!file.is_open()) 
			cout << "\n" << "File is not found.";
		while (getline(file, str)) {
						cout << str << '\n';
				}
		file.close();
	}

	//здесь выводятся "краковяки"
	string pathF ("C:/Users/Александр/source/repos/SkillboxSearchEngineMovie/SkillboxSearchEngineMovie/resources/Salyut 7.txt");
		cout<<"\n\n"<<"This is cracovyaki" << "\n\n";
	string str="";
	ifstream cfile;
	cfile.open(pathF);
	if (!cfile.is_open()) {
		cerr << "Unable to open file" << std::endl;
		return 1;
	}
	while (getline(cfile, str)) {
//		if (str.find(text) == std::string::npos)
			cout << str << '\n';
	}
	cfile.close();

	//Здесь тоже краковяки
	cout << "\n" <<"This is cracovyaki" << '\n';
	 str="";
	ifstream ffile;
	ffile.open("C:\\Users\\Александр\\Documents\\text for program\\movie summary\\Salyut 7.txt");
	if (!ffile.is_open())
	{
		cout << "\n" << "File is not open" << '\n';
	}
	while (getline(ffile, str)) {
		cout<<"Ok " << str << "\n";
	}
	ffile.close();
	cout << "\n\n";
	// Здесь выводится список файлов директории
	for (const auto& p : fs::directory_iterator("C:/Users/Александр/Documents/text for program/movie summary")) {
 cout<<"\n" << p.path() << "\n";
 }

//	string text= "C:\\Users\\Александр\\Documents\\text for program\movie summary\\Salyut 7.txt";
//	std::cout << "Input file name: ";// << std::flush;
//	std::getline(std::cin, text);
//	ifstream cfile("C:\\Users\\Александр\\source\\repos\\SkillboxSearchEngineMovie\\SkillboxSearchEngineMovie\\resources\\Seventeen Moments of Spring.txt", ios::binary);
//	ifstream cfile("C:\\Users\\Александр\\Documents\\text for program\movie summary\\Seventeen Moments of Spring.txt", ios::binary);
//	ifstream cfile("C:\\Users\\Александр\\source\\repos\\SkillboxSearchEngineMovie\\SkillboxSearchEngineMovie\\resources\\Seventeen Moments of Spring.txt");
//	cfile.open("C:/Users/Александр/Documents/text for program/movie summary/Salyut 7.txt");

//	string str = "Fyodorov";
//	std::getline(std::cin, text);
//	std::string line;
//if (cfile.bad()) {
//		cerr<<"\n" << "Ok!!!" << endl;
//	}

	
//	cfile.close();
//	filesystem::path p("C:\\Users\\Александр\\Documents\\text for program\\data.txt");
//		for (auto& p ::directory_iterator("C:\\Users\\Александр\\Documents\\text for program\\data.txt"))
//			cout << p.path() << '\n';
//		filesystem::space(p);
 //   for (const auto& item : configr.items())
//	{
	//	int i = stoi(item.key());
//		int i = configr["number"];
//		item.value() = configr["request"];
//		pair<int, string> oPair(i, item.value());
//		requests.movieRequests.insert(oPair);
//

//	}
//	cout << read[0] << "!!!\n";
//	for (auto it = requests.movieRequests.begin(); it !=requests.movieRequests.end(); ++it)
//		cout << it->second << "\n";

	return 0;
}
