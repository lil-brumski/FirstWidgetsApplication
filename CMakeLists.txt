cmake_minimum_required(VERSION 3.30)
project(FirstWidgetsApplication LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_AUTORCC ON)

if(LINUX)
    add_compile_options(
        -Wall
        -Wextra
        -Werror
    )
endif()

find_package(Qt6
    REQUIRED COMPONENTS
        Core
        Gui
        Widgets
)

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
        Qt6::Core
        Qt6::Gui
        Qt6::Widgets
)

## FOR second.exe
set(SECOND_PROJECT_SOURCES
    second.cpp
    second.hpp
    second.rc
)

qt_add_resources(SECOND_PROJECT_SOURCES second.qrc)

qt_add_executable(second ${SECOND_PROJECT_SOURCES})

set_target_properties(second
    PROPERTIES
        WIN32_EXECUTABLE TRUE
        MACOSX_BUNDLE TRUE
)

target_link_libraries(second
    PUBLIC
        Qt6::Core
        Qt6::Gui
        Qt6::Widgets
)
#target_precompile_headers(${PROJECT_NAME} PUBLIC stdafx.h)
