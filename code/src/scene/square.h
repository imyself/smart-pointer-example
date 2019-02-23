#pragma once

#include "drawable.h"
#include <la.h>

#include <QOpenGLContext>
#include <QOpenGLBuffer>
#include <QOpenGLShaderProgram>

class Square : public Drawable
{
public:
    Square(GLWidget277* context);
    void create(const std::vector<glm::vec4> &colors) override;
};
