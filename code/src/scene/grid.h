#pragma once
#include "drawable.h"
#include <la.h>

#include <QOpenGLContext>
#include <QOpenGLBuffer>
#include <QOpenGLShaderProgram>

class Grid : public Drawable
{
public:
    Grid(GLWidget277* context);
    void create(const std::vector<glm::vec4> &colors) override;

    GLenum drawMode() override;
};
