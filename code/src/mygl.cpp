#include "mygl.h"
#include <la.h>

#include <iostream>
#include <QApplication>
#include <QKeyEvent>


MyGL::MyGL(QWidget *parent)
    : GLWidget277(parent),
      grid(this), m_square(this),
      prog_flat(this),
      m_sceneDrawFunctionPtr(&MyGL::drawScene1),
      m_translateX(0), m_translateY(0), m_rotate(0),
      m_scaleX(1), m_scaleY(1)
{
}

MyGL::~MyGL()
{
    makeCurrent();

    glDeleteVertexArrays(1, &vao);
    grid.destroy();
}

void MyGL::initializeGL()
{
    // Create an OpenGL context using Qt's QOpenGLFunctions_3_2_Core class
    // If you were programming in a non-Qt context you might use GLEW (GL Extension Wrangler)instead
    initializeOpenGLFunctions();
    // Print out some information about the current OpenGL context
    debugContextVersion();

    // Set a few settings/modes in OpenGL rendering
    glEnable(GL_DEPTH_TEST);
    glEnable(GL_LINE_SMOOTH);
    glEnable(GL_POLYGON_SMOOTH);
    glHint(GL_LINE_SMOOTH_HINT, GL_NICEST);
    glHint(GL_POLYGON_SMOOTH_HINT, GL_NICEST);
    // Set the size with which points should be rendered
    glPointSize(5);
    // Set the color with which the screen is filled at the start of each render call.
    glClearColor(0.5, 0.5, 0.5, 1);

    printGLErrorLog();

    // Create a Vertex Attribute Object
//    vao.create(); DELETEME
    glGenVertexArrays(1, &vao);

    grid.create(std::vector<glm::vec4>());

    m_square.create(std::vector<glm::vec4>{glm::vec4(1,1,1,1), glm::vec4(0,1,1,1), glm::vec4(1,0,1,1), glm::vec4(1,1,0,1)});

    // Create and set up the flat lighting shader
    prog_flat.create("../ref_impl/glsl/flat.vert.glsl", "../ref_impl/glsl/flat.frag.glsl");

    // We have to have a VAO bound in OpenGL 3.2 Core. But if we're not
    // using multiple VAOs, we can just bind one once.
//    vao.bind();
    glBindVertexArray(vao);
}

void MyGL::resizeGL(int w, int h)
{
    //This code sets the concatenated view and perspective projection matrices used for
    //our scene's camera view.
    glm::mat4 viewproj = glm::scale(glm::mat4(), glm::vec3(0.2, 0.2, 0.2)); // Screen is -5 to 5

    // Upload the view-projection matrix to our shaders (i.e. onto the graphics card)

    prog_flat.setViewProjMatrix(viewproj);

    printGLErrorLog();
}

//This function is called by Qt any time your GL window is supposed to update
//For example, when the function updateGL is called, paintGL is called implicitly.
void MyGL::paintGL()
{
    // Clear the screen so that we only see newly drawn images
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    // Draw the grid
    prog_flat.setModelMatrix(glm::mat4());
    prog_flat.draw(*this, grid);

    // Invoke the function that draws the currently selected scene.
    // This is done via function pointer so we don't need an IF statement here.
    (this->*m_sceneDrawFunctionPtr)();
}


void MyGL::keyPressEvent(QKeyEvent *e)
{
    // http://doc.qt.io/qt-5/qt.html#Key-enum
    if (e->key() == Qt::Key_Escape) {
        QApplication::quit();
    }
}

void MyGL::slot_setTranslateX(int t)
{
    m_translateX = t;
    update();
}

void MyGL::slot_setTranslateY(int t)
{
    m_translateY = t;
    update();
}

void MyGL::slot_setRotate(int r)
{
    m_rotate = r;
    update();
}

void MyGL::slot_setScaleX(int s)
{
    m_scaleX = s;
    update();
}

void MyGL::slot_setScaleY(int s)
{
    m_scaleY = s;
    update();
}

void MyGL::slot_setScene1()
{
    m_sceneDrawFunctionPtr = &MyGL::drawScene1;
    update();
}

void MyGL::slot_setScene2()
{
    m_sceneDrawFunctionPtr = &MyGL::drawScene2;
    update();
}

void MyGL::slot_setScene3()
{
    m_sceneDrawFunctionPtr = &MyGL::drawScene3;
    update();
}
