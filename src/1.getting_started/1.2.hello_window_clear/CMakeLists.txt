add_executable(hello_widget main.cpp mainwindow.cpp mainwindow.h mainwindow.ui glwidget.h glwidget.cpp)
target_include_directories(hello_widget PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}) # ui_mainwindow.h
target_link_libraries(hello_widget PRIVATE Qt6::Core Qt6::Gui Qt6::OpenGL Qt6::OpenGLWidgets Qt6::Widgets)
