#include "grid.h"
#include <la.h>
#include <iostream>

const static int NUM_IDX = 36;

Grid::Grid(GLWidget277 *context) : Drawable(context)
{}

void Grid::create(const std::vector<glm::vec4>& colors)
{
    GLuint idx[NUM_IDX];
    glm::vec4 vertPos[NUM_IDX];
    glm::vec4 vertCol[NUM_IDX];

    for(int i = 0; i < NUM_IDX; i++)
    {
        idx[i] = i;
    }

    // -4 to 4
    for(int row = 0; row < 9; row++)
    {
        vertPos[row * 2] = glm::vec4(row - 4.f, 5.f, -1.f, 1.f);
        vertPos[row * 2 + 1] = glm::vec4(row - 4.f, -5.f, -1.f, 1.f);
    }
    for(int col = 0; col < 9; col++)
    {
        vertPos[col * 2 + 18] = glm::vec4(5.f, col - 4.f, -1.f, 1.f);
        vertPos[col * 2 + 19] = glm::vec4(-5.f, col - 4.f, -1.f, 1.f);
    }

    for(int i = 0; i < NUM_IDX; i++)
    {
        vertCol[i] = glm::vec4(0,0,0,1);
    }
    vertCol[8] = vertCol[9] = glm::vec4(1,1,1,1);
    vertCol[26] = vertCol[27] = glm::vec4(1,1,1,1);

    count = NUM_IDX;

    // Create a VBO on our GPU and store its handle in bufIdx
    generateIdx();
    // Tell OpenGL that we want to perform subsequent operations on the VBO referred to by bufIdx
    // and that it will be treated as an element array buffer (since it will contain triangle indices)
    context->glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, bufIdx);
    // Pass the data stored in cyl_idx into the bound buffer, reading a number of bytes equal to
    // CYL_IDX_COUNT multiplied by the size of a GLuint. This data is sent to the GPU to be read by shader programs.
    context->glBufferData(GL_ELEMENT_ARRAY_BUFFER, NUM_IDX * sizeof(GLuint), idx, GL_STATIC_DRAW);

    // The next few sets of function calls are basically the same as above, except bufPos and bufNor are
    // array buffers rather than element array buffers, as they store vertex attributes like position.
    generatePos();
    context->glBindBuffer(GL_ARRAY_BUFFER, bufPos);
    context->glBufferData(GL_ARRAY_BUFFER, NUM_IDX * sizeof(glm::vec4), vertPos, GL_STATIC_DRAW);

    generateCol();
    context->glBindBuffer(GL_ARRAY_BUFFER, bufCol);
    context->glBufferData(GL_ARRAY_BUFFER, NUM_IDX * sizeof(glm::vec4), vertCol, GL_STATIC_DRAW);
}

GLenum Grid::drawMode()
{
    return GL_LINES;
}
