cmake_minimum_required(VERSION 3.14)

project(12-Serialize-JSON LANGUAGES CXX)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS Core)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Core)

add_executable(12-Serialize-JSON
  main.cpp
  test.h
  test.cpp
  converter.h
  converter.cpp
)
target_link_libraries(12-Serialize-JSON Qt${QT_VERSION_MAJOR}::Core)

install(TARGETS 12-Serialize-JSON
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR})
