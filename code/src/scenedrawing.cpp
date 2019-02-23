#include "mygl.h"
#include "transforms.h"

void MyGL::drawScene1()
{
    glm::mat4 model = translate(m_translateX, m_translateY) * rotate(m_rotate) * scale(m_scaleX, m_scaleY);
    prog_flat.setModelMatrix(model);
    prog_flat.draw(*this, m_square);
}

void MyGL::drawScene2()
{
    glm::mat4 model = scale(m_scaleX,m_scaleY);
    prog_flat.setModelMatrix(model);
    prog_flat.draw(*this, m_square);
}

void MyGL::drawScene3()
{
    //TODO
}
