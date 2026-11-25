cmake_minimum_required(VERSION 3.16)

project(qt_mario VERSION 0.1 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(GAME_TYPE "Qt" CACHE STRING "Game backend: Qt, WindowsConsole or LinuxConsole")
set_property(CACHE GAME_TYPE PROPERTY STRINGS Qt WindowsConsole LinuxConsole)

if(GAME_TYPE STREQUAL "Qt")
	set(CMAKE_AUTOMOC ON)
	set(CMAKE_AUTORCC ON)
	set(CMAKE_AUTOUIC ON)

	find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS Widgets)
	find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Widgets)
else()
	set(CMAKE_AUTOMOC OFF)
	set(CMAKE_AUTORCC OFF)
	set(CMAKE_AUTOUIC OFF)
endif()

if(GAME_TYPE STREQUAL "LinuxConsole")
	find_package(Curses REQUIRED)
endif()

find_package(Threads REQUIRED)

add_subdirectory(src)
