#include "OGL_Triangle.hpp"

void OGL_TriangleVertexF(OGL_VertexObject& object){
    /* Lives on the CPU */
    /* We can have more attributes in here, for example vertex1 can also have R,G,B,A floats */
    const std::vector<GLfloat> vertexPos{
        /*  x      y     z */
        -0.5f, -0.3f, 0.5f, // Vertex 1 
        0.5f, -0.1f, 0.5f,  // Vertex 2
        0.3f, 0.3f, 0.8f,   // Vertex 3
    };
    /* z coord is ommited in 2D */

    /* VAO, lives in the GPU */
    glGenVertexArrays(1, &object.VAO);
    /* We select that array */
    glBindVertexArray(object.VAO);

    /* We now start generating the VBO */
    glGenBuffers(1, &object.VBO);
    /* We select that buffer */
    glBindBuffer(GL_ARRAY_BUFFER, object.VBO);
    /* Give our data to the VBO */
    glBufferData(GL_ARRAY_BUFFER, vertexPos.size() * sizeof(GLfloat), // Size of data
                vertexPos.data(), // Data 
                GL_STATIC_DRAW); // Give OpenGL, a "taste" of what we will use the VBO for

    /* Enable attributes of the vertex (position for example) */
    /* We tell OpenGL, how to use the VAO */
    glEnableVertexAttribArray(0);
    /* Configure the attributes of the vertex, and how we will move inside of it */
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

void OGL_TriangleVertex2D(OGL_VertexObject& object, float x1, float y1,\
                        float x2, float y2, float x3, float y3){
    /* Lives on the CPU */
    const std::vector<GLfloat> vertexPos{
        /*  x      y     z */
        x1, y1, 0.0f, // Vertex 1 
        x2, y2, 0.0f,  // Vertex 2
        x3, y3, 0.0f,   // Vertex 3
    };

    /* z coord is ommited in 2D*/

    /* VAO, lives in the GPU */
    glGenVertexArrays(1, &object.VAO);
    /* We select that array */
    glBindVertexArray(object.VAO);

    /* We now start generating the VBO */
    glGenBuffers(1, &object.VBO);
    /* We select that buffer */
    glBindBuffer(GL_ARRAY_BUFFER, object.VBO);
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
