# CMakeList.txt: файл проекта CMake верхнего уровня; проведите глобальную конфигурацию
# и включите сюда подпроекты.
#
cmake_minimum_required (VERSION 3.8)

project ("SkillboxSearchEngineMovie")
set(JSON_BuildTests OFF CACHE INTERNAL "")
#FetchContent(nlohmann.json)
 add_subdirectory(nlohmann.json)
# Включите подпроекты.
add_subdirectory ("SkillboxSearchEngineMovie")
#add_subdirectory ("functions")
