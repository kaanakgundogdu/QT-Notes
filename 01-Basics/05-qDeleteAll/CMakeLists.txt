cmake_minimum_required(VERSION 3.14)

project(05-qDeleteAll LANGUAGES CXX)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS Core)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Core)

add_executable(05-qDeleteAll
  main.cpp
  test.cpp
  test.h
)
target_link_libraries(05-qDeleteAll Qt${QT_VERSION_MAJOR}::Core)

install(TARGETS 05-qDeleteAll
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR})
