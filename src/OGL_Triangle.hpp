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

/**
 * @brief Creates the vertices of a 2D triangle, (z coord is fixed to 0.0f)
 * 
 * @attention Vertex positions are relative to the screen's centre (0,0)
 * 
 * @param VAO Vertex array object to access/bind
 * @param VBO Vertex buffer object to access/bind
 * @param x1 Vertex1 x position
 * @param y1 Vertex1 y position
 * @param x2 Vertex2 x position
 * @param y2 Vertex2 y position
 * @param x3 Vertex3 x position
 * @param y3 Vertex3 y position
 * 
 * @returns The created Vertex Array Object (VAO)
 */
void OGL_TriangleVertex2D(GLuint& VAO, GLuint& VBO, float x1, float y1,\
                        float x2, float y2, float x3, float y3);
