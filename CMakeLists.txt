cmake_minimum_required(VERSION 3.16)

project(learn-opengl LANGUAGES C CXX)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS Widgets)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Core Gui OpenGL Widgets)
if(${QT_VERSION_MAJOR} GREATER_EQUAL 6)
    find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS  OpenGLWidgets)
endif()

add_subdirectory(${PROJECT_SOURCE_DIR}/src/1.getting_started/1.2.hello_window_clear)
add_subdirectory(${PROJECT_SOURCE_DIR}/src/1.getting_started/2.2.hello_triangle_indexed)

