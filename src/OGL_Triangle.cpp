#include "OGL_Triangle.hpp"

void OGL_TriangleVertexF(GLuint& VAO, GLuint& VBO){
    /* Lives on the CPU */
    const std::vector<GLfloat> vertexPos{
        /*  x      y     z */
        -0.8f, -0.8f, 0.0f, // Vertex 1 
        0.8f, -0.8f, 0.0f,  // Vertex 2
        0.0f, 0.8f, 0.0f,   // Vertex 3
    };

    /* VAO, lives in the GPU */
    glGenVertexArrays(1, &VAO);
    /* We select that array */
    glBindVertexArray(VAO);

    /* We now start generating the VBO */
    glGenBuffers(1, &VBO);
    /* We select that buffer */
    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    /* Give our data to the VBO */
    glBufferData(GL_ARRAY_BUFFER, vertexPos.size() * sizeof(GLfloat), vertexPos.data(), GL_STATIC_DRAW);

    /* Enable attributes of the vertex (position for example)*/
    glEnableVertexAttribArray(0);
    /* Configure the attributes of the vertex */
    glVertexAttribPointer(0, 
                        3, // Number of elements in each vertex
                        GL_FLOAT, // type of element
                        GL_FALSE,
                        sizeof(GLfloat) * 3, // Bytes per element
                        (void*)0); // Offset

    /* Cleanup, to close the arrays/buffers */
    glBindVertexArray(0);
    glDisableVertexAttribArray(0);

    return;
}
