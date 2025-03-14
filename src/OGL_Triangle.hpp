#include "../ThirdParty/GLAD/include/glad/glad.h" /* OpenGL */

#include "OGL_Object.hpp"

#include <vector> /* For the vertices */

#pragma once

/**
 * @brief Creates the vertices of a triangle (fixed)
 * 
 * @param object Containts both the VBO and VAO
 * 
 * @note VBO, and VAO hold only positions, not colours
 */
void OGL_TriangleVertexF(OGL_VertexObject& object);

/**
 * @brief Creates the vertices of a triangle (fixed, coloured)
 * 
 * @param object Containts both the VBO and VAO
 * 
 * @note VBO, and VAO hold positions and colours
 */
void OGL_TriangleVertexFC(OGL_VertexObject& object);