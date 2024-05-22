#ifndef GLWIDGET_H
#define GLWIDGET_H

#include <QOpenGLWidget>
#include <QOpenGLBuffer>
#include <QOpenGLShaderProgram>
#include <QOpenGLFunctions_3_3_Core>

class GLWidget : public QOpenGLWidget, protected QOpenGLFunctions_3_3_Core
{
    Q_OBJECT

public:
    enum class Shape
    {
        NONE,
        RECTANGLE
    };

    enum class PolygonMode
    {
        POINT,
        LINE,
        FILL,
    };

public:
    explicit GLWidget(QWidget *parent = nullptr);
    ~GLWidget();

    void drawShape(enum Shape shape);
    void setPolygonMode(enum PolygonMode mode);

protected:
    void initializeGL() override;
    void paintGL() override;
    void resizeGL(int w, int h) override;

private:
    GLuint m_VAO;
    GLuint m_VBO;
    GLuint m_EBO;
    QOpenGLShaderProgram m_program;
    enum Shape m_shape;
};

#endif // GLWIDGET_H
