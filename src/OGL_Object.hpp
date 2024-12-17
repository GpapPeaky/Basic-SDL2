#pragma once

#include <iostream>
#include <vector>
#include "../ThirdParty/SDL2/include/SDL2/SDL.h"
#include "../ThirdParty/GLAD/include/glad/glad.h"

/**
 * @brief Vertex positions index in the VBOs vector
 */
#define OGL_VERTEX_POS_IDX 0

/**
 * @brief Vertex red/green/blue values index in the VBOs vector
 */
#define OGL_VERTEX_RGB_IDX 1

/**
 * @brief Contains The Vertex Buffer Objects and Vertex Array Object
 */
typedef struct OGL_VertexObject{
    GLuint VAO; /* Vertex array object */
    GLuint positionVBO; /* positions: vertex buffer object */
    /* By adding more 'VBOs' we can give more data to each object */
    /* And if it is not required, we simply do not engage with the fields */
    GLuint RGBVBO; /* colours: vertex buffer object */
}OGL_VertexObject;
