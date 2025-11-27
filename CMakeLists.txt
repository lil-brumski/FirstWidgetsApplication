cmake_minimum_required(VERSION 3.16)
project(FirstWidgetsApplication LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS Core)
find_package(Qt${QT_VERSION_MAJOR}
    COMPONENTS
        Core
        Gui
        Widgets
)

if(QT_VERSION VERSION_LESS 6.3)
    macro(qt_standard_project_setup)
        set(CMAKE_AUTOMOC ON)
        set(CMAKE_AUTOUIC ON)
    endmacro()
endif()

if(QT_VERSION VERSION_LESS 6.0)
    macro(qt_add_executable name)
         if(ANDROID)
            add_library(name SHARED ${ARGN})
        else()
            add_executable(${ARGV})
        endif()
    endmacro()
endif()

qt_standard_project_setup()

set(PROJECT_SOURCES
    main.cpp
    FirstWidgetsApplication.rc
)

qt_add_executable(${PROJECT_NAME} ${PROJECT_SOURCES})

set_target_properties(${PROJECT_NAME}
    PROPERTIES
        WIN32_EXECUTABLE TRUE
)

target_link_libraries(${PROJECT_NAME}
    PUBLIC
        Qt::Core
        Qt::Gui
        Qt::Widgets
)

## FOR second.exe
set(SECOND_PROJECT_SOURCES
    second.cpp
    second.hpp
    second.rc
)

qt_add_executable(second ${SECOND_PROJECT_SOURCES})

set_target_properties(second
    PROPERTIES
        WIN32_EXECUTABLE TRUE
)

target_link_libraries(second
    PUBLIC
        Qt::Core
        Qt::Gui
        Qt::Widgets
)
#target_precompile_headers(${PROJECT_NAME} PUBLIC stdafx.h)
