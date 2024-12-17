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
    /* The VAO tells us about the attributes of the object */
    glGenVertexArrays(1, &object.VAO);
    /* We select that array */
    glBindVertexArray(object.VAO);

    /* We now start generating the VBO */
    /* We only want the position index, since we have no specified colour here */
    glGenBuffers(1, &object.positionVBO);
    /* We select that buffer */
    glBindBuffer(GL_ARRAY_BUFFER, object.positionVBO);
    /* Give our data to the VBO */
    glBufferData(GL_ARRAY_BUFFER, vertexPos.size() * sizeof(GLfloat), // Size of data
                vertexPos.data(), // Data 
                GL_STATIC_DRAW); // Give OpenGL, a "taste" of what we will use the VBO for

    /* Enable attributes of the vertex (position for example) */
    /* We tell OpenGL, how to use the VAO */
    /* Specifically, we link the index of the data in VAO, to the corresponding data in the VBO */
    /* We enable index 0 */
    glEnableVertexAttribArray(0);
    /* Configure the attributes of the vertex, and how we will move inside of it */
    glVertexAttribPointer(0, // VAO index, and how to handle it
                        3, // Number of elements in each vertex
                        GL_FLOAT, // type of element
                        GL_FALSE,
                        sizeof(GLfloat) * 3, // Bytes per element
                        (void*)0); // Offset

    /* We can set a new VBO for the R,G,B data (see OGL_TriangleVertexFC(...))*/

    /* Cleanup, to close the arrays/buffers */
    glBindVertexArray(0);
    glDisableVertexAttribArray(0);

    return;
}

void OGL_TriangleVertexFC(OGL_VertexObject& object){
    /* Lives on the CPU */
    /* We can have more attributes in here, for example vertex1 can also have R,G,B,A floats */
    const std::vector<GLfloat> vertexPos{
        /*  x      y     z */
        0.0f, -0.2f, 0.2f, // Vertex 1 
        0.1f, -0.1f, 0.2f,  // Vertex 2
        0.1f, 0.2f, 0.1f,   // Vertex 3
    };
    /* z coord is ommited in 2D */
    const std::vector<GLfloat> vertexRGB{
        /* R     G      B */
        1.0f, 0.0f, 0.0f,
        0.0f, 1.0f, 0.0f,
        0.0f, 0.0f, 1.0f
    };
    /* VAO, lives in the GPU */
    /* The VAO tells us about the attributes of the object */
    glGenVertexArrays(1, &object.VAO);
    /* We select that array */
    glBindVertexArray(object.VAO);

    /* Vertex position VBO */

    /* We now start generating the VBO */
    glGenBuffers(1, &object.positionVBO);
    /* We select that buffer, we specifically pass the position VBO */
    glBindBuffer(GL_ARRAY_BUFFER, object.positionVBO);
    /* Give our data to the VBO */
    glBufferData(GL_ARRAY_BUFFER, vertexPos.size() * sizeof(GLfloat), // Size of data
                vertexPos.data(), // Data 
                GL_STATIC_DRAW); // Give OpenGL, a hint of what we will use the data for

    /* Enable attributes of the vertex (position for example) */
    /* We tell OpenGL, how to use the VAO */
    /* Specifically, we link the index of the data in VAO, to the corresponding data in the VBO */
    /* We enable index 0 */
    glEnableVertexAttribArray(0);
    /* Configure the attributes of the vertex, and how we will move inside of it */
    glVertexAttribPointer(0, // VAO index, and how to handle it
                        3, // Number of elements in each vertex
                        GL_FLOAT, // type of element
                        GL_FALSE,
                        sizeof(GLfloat) * 3, // Bytes per element
                        (void*)0); // Offset

    /* Vertex colour VBO */

    /* We genereate the RGB VBO */
    glGenBuffers(1, &object.RGBVBO);
    glBindBuffer(GL_ARRAY_BUFFER, object.RGBVBO);
    glBufferData(GL_ARRAY_BUFFER, vertexRGB.size() * sizeof(GLfloat),
                vertexRGB.data(),
                GL_STATIC_DRAW);

    /* We tell OpenGL, how to use the VAO */
    /* Specifically, we link the index of the data in VAO, to the corresponding data in the VBO */
    /* We enable index 1 (RGB values) */
    glEnableVertexAttribArray(1);
    /* Configure the attributes of the vertex, and how we will move inside of it */
    glVertexAttribPointer(1, // VAO index, and how to handle it
                        3, // r, g, b
                        GL_FLOAT, // type of element
                        GL_FALSE,
                        0, // Bytes per element
                        (void*)0); // Offset

    /* Cleanup, to close the arrays/buffers */
    glBindVertexArray(0);
    /* We disable the pointers to the objects attributes */
    glDisableVertexAttribArray(0);
    glDisableVertexAttribArray(1);

    return;
}
