cmake_minimum_required(VERSION 3.5)

project(qt_sqlite_app LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

#find_package(Qt5 COMPONENTS Widgets Sql REQUIRED)
find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS Widgets)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Widgets)
find_package(Qt6 REQUIRED COMPONENTS Widgets Sql)
find_package(Qt6 COMPONENTS Core Sql REQUIRED)

add_executable(qt_sqlite_app
    main.cpp
    MainWindow.cpp
    MainWindow.h
    MainWindow.ui
)

#target_link_libraries(qt_sqlite_app Qt5::Widgets Qt5::Sql)
target_link_libraries(qt_sqlite_app PRIVATE Qt${QT_VERSION_MAJOR}::Widgets Qt${QT_VERSION_MAJOR}::Sql)
