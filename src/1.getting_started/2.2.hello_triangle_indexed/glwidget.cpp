#include "glwidget.h"

GLWidget::GLWidget(QWidget *parent)
    : QOpenGLWidget(parent)
    , m_shape(Shape::NONE)
{
}

GLWidget::~GLWidget()
{
    makeCurrent();

    glDeleteVertexArrays(1, &m_VAO);
    glDeleteBuffers(1, &m_VBO);
    glDeleteBuffers(1, &m_EBO);

    doneCurrent();
}

void GLWidget::drawShape(Shape shape)
{
    m_shape = shape;
    update();
}

void GLWidget::setWireFrame(bool isWireFrame)
{
    makeCurrent();

    if (isWireFrame)
        glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
    else
        glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);

    update();

    doneCurrent();
}

void GLWidget::initializeGL()
{
    initializeOpenGLFunctions();

    // build and compile shader program
    m_program.addShaderFromSourceFile(QOpenGLShader::Vertex, ":/shader/model.vert");
    m_program.addShaderFromSourceFile(QOpenGLShader::Fragment, ":/shader/model.frag");
    m_program.link();

    // set up vertex data (and buffer(s)) and configure vertex attributes
    GLfloat vertices[] = {
         0.5f,  0.5f, 0.0f,  // top right
         0.5f, -0.5f, 0.0f,  // bottom right
        -0.5f, -0.5f, 0.0f,  // bottom left
        -0.5f,  0.5f, 0.0f   // top left
    };

    GLuint indices[] = {
        0, 1, 3,  // first Triangle
        1, 2, 3   // second Triangle
    };

    // bind the Vertex Array Object first,
    glGenVertexArrays(1, &m_VAO);
    glBindVertexArray(m_VAO);

    // then bind and set vertex buffer(s),
    glGenBuffers(1, &m_VBO);
    glBindBuffer(GL_ARRAY_BUFFER, m_VBO);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

    // and then configure vertex attributes(s).
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
    glEnableVertexAttribArray(0);

    // note that this is allowed, the call to glVertexAttribPointer registered VBO as the vertex attribute's bound vertex buffer object so afterwards we can safely unbind
    glBindBuffer(GL_ARRAY_BUFFER, 0);

    // bind the Element Buffer Object
    glGenBuffers(1, &m_EBO);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_EBO);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);

    // REMEMBER: do NOT unbind the EBO while a VAO is active as the bound element buffer object IS stored in the VAO; keep the EBO bound.

    // You can unbind the VAO afterwards so other VAO calls won't accidentally modify this VAO, but this rarely happens. Modifying other
    // VAOs requires a call to glBindVertexArray anyways so we generally don't unbind VAOs (nor VBOs) when it's not directly necessary.
    glBindVertexArray(0);
}

void GLWidget::paintGL()
{
    glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT);

    m_program.bind();
    glBindVertexArray(m_VAO);

    switch (m_shape)
    {
    case Shape::NONE:
        break;
    case Shape::RECTANGLE:
        glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
        break;
    default:
        break;
    }

    // QMetaObject::invokeMethod(this, "update", Qt::QueuedConnection);
}

void GLWidget::resizeGL(int w, int h)
{
    glViewport(0, 0, w, h);
}

