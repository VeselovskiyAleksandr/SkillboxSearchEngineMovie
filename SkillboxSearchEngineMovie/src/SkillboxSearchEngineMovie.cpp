// SkillboxSearchEngineMovie.cpp: определяет точку входа для приложения.
#include <string>
#include "SkillboxSearchEngineMovie.h"
#include "ConverterJSON.cpp"


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
//	 for (auto it = converterJSON.configuration.movieTitles.begin(); it != converterJSON.configuration.movieTitles.end(); ++it)
//		 cout << it->second << '\n';
	 converterJSON.openFile("requests.json");
	 converterJSON.openFile("answers.json");
	 converterJSON.requerysInputFunction(converterJSON.getRequests);
	 converterJSON.searchAnswersFunction();
	 //
// Здесь выводит нормально
//	 char buffer[1000];
//	 for (const auto& p : fs::directory_iterator("C:\\Users\\Александр\\source\\repos\\SkillboxSearchEngineMovie\\SkillboxSearchEngineMovie\\resources"))
//	 {
//	filesystem::path ("C:\\Users\\Александр\\Documents\\text for program\\data.txt");
//		for (auto& p ::directory_iterator("C:\\Users\\Александр\\Documents\\text for program\\data.txt"))
//	for (auto& it::directory_iterator(it)) {
//		cout << p.path() << '\n';
//	}
//	for (auto it = requests.movieRequests.begin(); it !=requests.movieRequests.end(); ++it)
//		cout << it->second << "\n";

	return 0;
}
