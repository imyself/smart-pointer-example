#include "square.h"
#include <la.h>

Square::Square(GLWidget277 *context) : Drawable(context)
{}

void Square::create(const std::vector<glm::vec4>& colors)
{
    GLuint idx[6]{0, 1, 2, 0, 2, 3};
    glm::vec4 vertPos[4]{glm::vec4(1.f, 1.f, 0, 1), glm::vec4(-1.f, 1.f, 0, 1), glm::vec4(-1.f, -1.f, 0, 1), glm::vec4(1.f, -1.f, 0, 1)};

    count = 6;

    // Create a VBO on our GPU and store its handle in bufIdx
    generateIdx();
    // Tell OpenGL that we want to perform subsequent operations on the VBO referred to by bufIdx
    // and that it will be treated as an element array buffer (since it will contain triangle indices)
    context->glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, bufIdx);
    // Pass the data stored in cyl_idx into the bound buffer, reading a number of bytes equal to
    // CYL_IDX_COUNT multiplied by the size of a GLuint. This data is sent to the GPU to be read by shader programs.
    context->glBufferData(GL_ELEMENT_ARRAY_BUFFER, 6 * sizeof(GLuint), idx, GL_STATIC_DRAW);

    // The next few sets of function calls are basically the same as above, except bufPos and bufNor are
    // array buffers rather than element array buffers, as they store vertex attributes like position.
    generatePos();
    context->glBindBuffer(GL_ARRAY_BUFFER, bufPos);
    context->glBufferData(GL_ARRAY_BUFFER, 4 * sizeof(glm::vec4), vertPos, GL_STATIC_DRAW);

    generateCol();
    context->glBindBuffer(GL_ARRAY_BUFFER, bufCol);
    context->glBufferData(GL_ARRAY_BUFFER, 4 * sizeof(glm::vec4), colors.data(), GL_STATIC_DRAW);
}
