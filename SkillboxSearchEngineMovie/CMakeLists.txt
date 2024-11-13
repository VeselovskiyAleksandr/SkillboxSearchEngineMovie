# CMakeList.txt: проект CMake для SkillboxSearchEngineMovie; включите исходный код и определения,
# укажите здесь логику для конкретного проекта.

cmake_minimum_required (VERSION 3.8)
# Добавьте источник в исполняемый файл этого проекта.
add_executable (SkillboxSearchEngineMovie "src/SkillboxSearchEngineMovie.cpp" "include/SkillboxSearchEngineMovie.h" "src/configurationCounter.cpp" "include/configurationCounter.h" "src/Configuration.cpp" "include/Configuration.h" "src/ConverterJSON.cpp" "include/ConverterJSON.h"  )
# TODO: Добавьте тесты и целевые объекты, если это необходимо.
target_link_libraries(SkillboxSearchEngineMovie PRIVATE nlohmann_json::nlohmann_json)
target_include_directories(SkillboxSearchEngineMovie PUBLIC include)
