#include "../ThirdParty/SDL2/include/SDL2/SDL.h"
#include "../ThirdParty/GLAD/include/glad/glad.h"
#include "OGL_Shader.hpp" // For creating the shader object to be used in the graphics pipeline
#include "OGL_Object.hpp" // For the vertex object abstraction
#include "SDL2_InitWin.hpp" // For creating the shader object to be used in the graphics pipeline

#pragma once

/**
 * @brief Creates the graphics pipeline, with the vertex and
 * fragment shader
 * 
 * @param vs Vertex shader to attach to the object
 * @param fs Fragment shader to attach to the object
 * 
 * @returns Object to store the shaders
 */
GLuint OGL_CreateGraphicsPipeline(const std::string& vs, const std::string& fs);
 
/**
 * @brief Pre draws to the window, sets OpenGL's state
 * 
 * @param graphicsPipeline Instruct what graphics pipeline to use
 */
void OGL_PreDraw(GLuint graphicsPipeline);

/**
 * @brief Draws the pre-drawn assets to the window
 *  
 * @param VAO Vertex array object to draw
 * @param VBO Vertex buffer object to draw from
 */
void OGL_Draw(GLuint VAO, GLuint VBO);

/**
 * @brief Draws an object
 * 
 * @param object Object to draw
 */
void OGL_DrawObject(OGL_VertexObject object);
