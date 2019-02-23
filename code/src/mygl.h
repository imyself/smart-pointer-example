#ifndef MYGL_H
#define MYGL_H

#include <glwidget277.h>
#include <utils.h>
#include <shaderprogram.h>
#include <scene/square.h>
#include <scene/grid.h>

#include <QOpenGLVertexArrayObject>
#include <QOpenGLShaderProgram>


class MyGL
    : public GLWidget277
{
    Q_OBJECT
private:
    ShaderProgram prog_flat;// A shader program that uses "flat" reflection (no shadowing at all)

    GLuint vao; // A handle for our vertex array object. This will store the VBOs created in our geometry classes.

    Grid grid;

    Square m_square;

    int m_translateX, m_translateY, m_rotate, m_scaleX, m_scaleY;

    void (MyGL::*m_sceneDrawFunctionPtr)(void);


public:
    explicit MyGL(QWidget *parent = 0);
    ~MyGL();

    void initializeGL();
    void resizeGL(int w, int h);
    void paintGL();

    void drawScene1();
    void drawScene2();
    void drawScene3();

protected:
    void keyPressEvent(QKeyEvent *e);

public slots:
    void slot_setTranslateX(int);
    void slot_setTranslateY(int);
    void slot_setRotate(int);
    void slot_setScaleX(int);
    void slot_setScaleY(int);

    void slot_setScene1();
    void slot_setScene2();
    void slot_setScene3();
};


#endif // MYGL_H
