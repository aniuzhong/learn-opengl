#include "glwidget.h"

GLWidget::GLWidget(QWidget *parent)
    : QOpenGLWidget(parent)
{
}

GLWidget::~GLWidget()
{
}

void GLWidget::initializeGL()
{
    initializeOpenGLFunctions();
}

void GLWidget::paintGL()
{
    glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT);

    // QMetaObject::invokeMethod(this, "update", Qt::QueuedConnection);/
}

void GLWidget::resizeGL(int w, int h)
{
    glViewport(0, 0, w, h);
}
