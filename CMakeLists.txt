cmake_minimum_required(VERSION 3.4)
project(QtShortcutTestDemo)

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTOUIC ON)
set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(CMAKE_PREFIX_PATH "D:/qt5.90/5.9/msvc2017_64")

add_executable(${PROJECT_NAME}
	./main.cpp
	./mainwindow.cpp
	./mainwindow.h
	./mainwindow.ui
	)
	
 source_group("hFile",FILES ./mainwindow.h)
 source_group("src", FILES ./main.cpp ./mainwindow.cpp)
 source_group("uiFile",FILES ./mainwindow.ui)

find_package(Qt5 COMPONENTS Widgets Core Gui REQUIRED)
target_link_libraries(${PROJECT_NAME}
	PUBLIC
	Qt5::Widgets
	Qt5::Core
	Qt5::Gui
	)