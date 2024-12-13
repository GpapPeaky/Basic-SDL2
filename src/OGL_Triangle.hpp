#include "../ThirdParty/GLAD/include/glad/glad.h" /* OpenGL */
#include <vector> /* For the vertices */

#pragma once

/**
 * @brief Creates the vertices of a triangle (fixed)
 * 
 * @param VAO Vertex array object to access/bind
 * @param VBO Vertex buffer object to access/bind
 * 
 * @returns The created Vertex Array Object (VAO)
 */
void OGL_TriangleVertexF(GLuint& VAO, GLuint& VBO);
