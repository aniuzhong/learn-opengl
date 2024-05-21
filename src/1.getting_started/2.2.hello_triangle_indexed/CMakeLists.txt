add_executable(hello_triangle_indexed
    main.cpp
    mainwindow.cpp
    mainwindow.h
    mainwindow.ui
    glwidget.h
    glwidget.cpp
    hello_triangle_indexed.qrc
)
# ui_mainwindow.h include "glwidget.h"
target_include_directories(hello_triangle_indexed PRIVATE ${CMAKE_CURRENT_SOURCE_DIR})
target_link_libraries(hello_triangle_indexed PRIVATE
    Qt6::Core
    Qt6::Gui
    Qt6::OpenGL
    Qt6::Widgets
    Qt6::OpenGLWidgets
)
