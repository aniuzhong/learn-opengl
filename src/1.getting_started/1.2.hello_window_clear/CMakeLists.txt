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
    Qt6::Core
    Qt6::Gui
    Qt6::OpenGL
    Qt6::OpenGLWidgets
    Qt6::Widgets
)
