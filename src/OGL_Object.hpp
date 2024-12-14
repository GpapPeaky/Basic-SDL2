#pragma once

#include <iostream>
#include "../ThirdParty/SDL2/include/SDL2/SDL.h"
#include "../ThirdParty/GLAD/include/glad/glad.h"

/**
 * @brief Contains The Vertex Buffer Object and Vertex Array Object
 */
typedef struct OGL_VertexObject{
    GLuint VAO;
    GLuint VBO;
}OGL_VertexObject;
