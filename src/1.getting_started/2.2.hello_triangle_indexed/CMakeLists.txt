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
    Qt${QT_VERSION_MAJOR}::Core
    Qt${QT_VERSION_MAJOR}::Gui
    Qt${QT_VERSION_MAJOR}::Widgets
    Qt${QT_VERSION_MAJOR}::OpenGL
)
if(${QT_VERSION_MAJOR} GREATER_EQUAL 6)
    target_link_libraries(hello_triangle_indexed PRIVATE Qt${QT_VERSION_MAJOR}::OpenGLWidgets)
endif()
