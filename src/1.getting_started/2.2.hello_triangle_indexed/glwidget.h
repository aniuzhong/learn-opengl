#ifndef GLWIDGET_H
#define GLWIDGET_H

#include <QOpenGLWidget>
#include <QOpenGLBuffer>
#include <QOpenGLShaderProgram>
#include <QOpenGLFunctions_3_3_Core>
#include <QOpenGLVertexArrayObject>

class GLWidget : public QOpenGLWidget, protected QOpenGLFunctions_3_3_Core
{
    Q_OBJECT

public:
    explicit GLWidget(QWidget *parent = nullptr);
    ~GLWidget();

protected:
    void initializeGL() override;
    void paintGL() override;
    void resizeGL(int w, int h) override;

private:
    GLuint               m_VAO;
    GLuint               m_VBO;
    GLuint               m_EBO;
    QOpenGLShaderProgram m_program;
};

#endif // GLWIDGET_H
