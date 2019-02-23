#pragma once

#include <la.h>

glm::mat4 translate(float x, float y)
{
    return glm::translate(glm::vec3(x, y, 0));
}

glm::mat4 rotate(float deg)
{
    return glm::rotate(deg, glm::vec3(0,0,1));
}

glm::mat4 scale(float x, float y)
{
    return glm::scale(glm::vec3(x, y, 1));
}
