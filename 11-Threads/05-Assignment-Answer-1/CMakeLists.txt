cmake_minimum_required(VERSION 3.14)

project(05-Assignment-Answer-1 LANGUAGES CXX)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(QT NAMES Qt6 Qt5 COMPONENTS Core Concurrent REQUIRED)
find_package(Qt${QT_VERSION_MAJOR} COMPONENTS Core Concurrent REQUIRED)

add_executable(05-Assignment-Answer-1
  main.cpp
)

target_link_libraries(05-Assignment-Answer-1 Qt${QT_VERSION_MAJOR}::Core Qt${QT_VERSION_MAJOR}::Concurrent)

install(TARGETS 05-Assignment-Answer-1
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR})
