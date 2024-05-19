cmake_minimum_required(VERSION 3.16)

project(LearnOpenGL LANGUAGES C CXX)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(Qt6 REQUIRED COMPONENTS Core Gui OpenGL OpenGLWidgets Widgets)

add_subdirectory(${PROJECT_SOURCE_DIR}/src/1.getting_started/1.2.hello_window_clear)
