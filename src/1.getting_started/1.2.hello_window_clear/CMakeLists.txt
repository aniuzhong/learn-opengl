add_executable(hello_window_clear
    main.cpp
    mainwindow.cpp
    mainwindow.h
    mainwindow.ui
    glwidget.h
    glwidget.cpp
)
# ui_mainwindow.h include "glwidget.h"
target_include_directories(hello_window_clear PRIVATE ${CMAKE_CURRENT_SOURCE_DIR})
target_link_libraries(hello_window_clear PRIVATE
    Qt${QT_VERSION_MAJOR}::Core
    Qt${QT_VERSION_MAJOR}::Gui
    Qt${QT_VERSION_MAJOR}::Widgets
    Qt${QT_VERSION_MAJOR}::OpenGL
)
if(${QT_VERSION_MAJOR} GREATER_EQUAL 6)
    target_link_libraries(hello_window_clear PRIVATE Qt${QT_VERSION_MAJOR}::OpenGLWidgets)
endif()

